from typing import Dict, List
from datamodel import OrderDepth, TradingState, Order
import pandas as pd
import numpy as np

class Trader:
    def __init__(self):
        self.position_limits = {
            "SQUID_INK": 50, "PICNIC_BASKET1": 50, "PICNIC_BASKET2": 50,
            "RAINFOREST_RESIN": 50, "KELP": 50, "CROISSANTS": 50,
            "JAMS": 50, "DJEMBES": 50, "VOLCANIC_ROCK": 400,
            "VOLCANIC_ROCK_VOUCHER_9500": 200, "VOLCANIC_ROCK_VOUCHER_9750": 200,
            "VOLCANIC_ROCK_VOUCHER_10000": 200, "VOLCANIC_ROCK_VOUCHER_10250": 200,
            "VOLCANIC_ROCK_VOUCHER_10500": 200
        }
        self.positions = {product: 0 for product in self.position_limits}
        self.fair_values = {product: None for product in self.position_limits}
        self.voucher_details = {
            "VOLCANIC_ROCK_VOUCHER_9500": {"strike": 9500, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_9750": {"strike": 9750, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10000": {"strike": 10000, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10250": {"strike": 10250, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10500": {"strike": 10500, "days_left": 7}
        }
        self.round = 0
        self.price_history = {product: [] for product in self.position_limits}
        self.volatility = {product: 0.2 for product in self.position_limits}
        self.cumulative_pnl = 0
        self.target_pnl = 100000

    def update_fair_value(self, product: str, state: TradingState):
        if product not in state.order_depths:
            return
            
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        
        if buy_orders and sell_orders:
            best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
            total_bid_volume = sum(qty for _, qty in buy_orders[:3])
            total_ask_volume = sum(qty for _, qty in sell_orders[:3])
            
            # Avoid division by zero
            if total_bid_volume + total_ask_volume > 0:
                mid_price = (best_bid * total_ask_volume + best_ask * total_bid_volume) / (total_bid_volume + total_ask_volume)
            else:
                mid_price = (best_bid + best_ask) / 2
                
            self.fair_values[product] = mid_price
            self.price_history[product].append(mid_price)
            
            if len(self.price_history[product]) >= 20:
                self.volatility[product] = np.std(self.price_history[product][-20:]) / mid_price if mid_price > 0 else 0.2

    def calculate_voucher_value(self, voucher: str, rock_price: float) -> float:
        if rock_price is None or rock_price <= 0:
            return 0.0
            
        strike = self.voucher_details[voucher]["strike"]
        days_left = self.voucher_details[voucher]["days_left"]
        time_to_expiry = days_left / 365
        volatility = self.volatility.get("VOLCANIC_ROCK", 0.2)
        risk_free_rate = 0.02
        
        if time_to_expiry <= 0:
            return max(0, rock_price - strike)
            
        try:
            d1 = (np.log(rock_price / strike) + (risk_free_rate + 0.5 * volatility ** 2) * time_to_expiry) / \
                 (volatility * np.sqrt(time_to_expiry))
            d2 = d1 - volatility * np.sqrt(time_to_expiry)
            
            def norm_cdf(x):
                return (1.0 + np.tanh(x / np.sqrt(2))) / 2.0
                
            call_value = rock_price * norm_cdf(d1) - strike * np.exp(-risk_free_rate * time_to_expiry) * norm_cdf(d2)
            return max(0, call_value)
        except (ValueError, ZeroDivisionError):
            return max(0, rock_price - strike)  # Fallback to intrinsic value

    def calculate_delta(self, voucher: str, rock_price: float) -> float:
        if rock_price is None or rock_price <= 0:
            return 0.0
            
        strike = self.voucher_details[voucher]["strike"]
        days_left = self.voucher_details[voucher]["days_left"]
        time_to_expiry = days_left / 365
        volatility = self.volatility.get("VOLCANIC_ROCK", 0.2)
        
        if time_to_expiry <= 0:
            return 1.0 if rock_price > strike else 0.0
            
        try:
            d1 = (np.log(rock_price / strike) + (0.02 + 0.5 * volatility ** 2) * time_to_expiry) / \
                 (volatility * np.sqrt(time_to_expiry))
            
            def norm_cdf(x):
                return (1.0 + np.tanh(x / np.sqrt(2))) / 2.0
                
            return norm_cdf(d1)
        except (ValueError, ZeroDivisionError):
            return 0.5  # Neutral delta on error

    def hedge_position(self, voucher: str, delta: float, state: TradingState) -> List[Order]:
        orders = []
        if "VOLCANIC_ROCK" not in state.order_depths:
            return orders
            
        rock_position = self.positions.get("VOLCANIC_ROCK", 0)
        voucher_position = self.positions[voucher]
        target_hedge = -voucher_position * delta
        current_exposure = rock_position
        hedge_needed = int(target_hedge - current_exposure)
        
        order_depth = state.order_depths["VOLCANIC_ROCK"]
        position_limit = self.position_limits["VOLCANIC_ROCK"]
        
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        
        if not (buy_orders and sell_orders):
            return orders
            
        best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
        best_bid_qty = buy_orders[0][1]
        best_ask_qty = sell_orders[0][1]

        if hedge_needed > 0 and rock_position < position_limit and best_ask:
            qty = min(hedge_needed, best_ask_qty, position_limit - rock_position)
            if qty > 0:
                orders.append(Order("VOLCANIC_ROCK", best_ask, qty))
                
        elif hedge_needed < 0 and rock_position > -position_limit and best_bid:
            qty = min(-hedge_needed, best_bid_qty, rock_position + position_limit)
            if qty > 0:
                orders.append(Order("VOLCANIC_ROCK", best_bid, -qty))
                
        return orders

    def run(self, state: TradingState) -> (Dict[str, List[Order]], int, str):
        self.round += 1
        result = {}
        conversions = 0
        trader_data = ""

        for product in self.positions:
            self.positions[product] = state.position.get(product, 0)

        for voucher in self.voucher_details:
            self.voucher_details[voucher]["days_left"] = max(0, 7 - self.round + 1)

        for product in state.order_depths:
            self.update_fair_value(product, state)

        rock_price = self.fair_values.get("VOLCANIC_ROCK", None)
        risk_factor = 1.0 if self.cumulative_pnl < 0.8 * self.target_pnl else 0.5

        for voucher in self.voucher_details:
            if voucher not in state.order_depths:
                continue
                
            order_depth = state.order_depths[voucher]
            current_position = self.positions[voucher]
            position_limit = self.position_limits[voucher]
            orders = []
            
            voucher_value = self.calculate_voucher_value(voucher, rock_price)
            if voucher_value is None or voucher_value < 0:
                continue
                
            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            
            if not (buy_orders and sell_orders):
                continue
                
            best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
            best_bid_qty = buy_orders[0][1]
            best_ask_qty = sell_orders[0][1]

            volatility = self.volatility.get(voucher, 0.2)
            Controller spread = max(1, int(1 + volatility * 50 * risk_factor))
            our_bid = max(1, int(voucher_value - spread))
            our_ask = int(voucher_value + spread)

            total_bid_volume = sum(qty for _, qty in buy_orders[:3])
            total_ask_volume = sum(qty for _, qty in sell_orders[:3])
            liquidity = min(total_bid_volume, total_ask_volume)
            max_trade_size = min(position_limit, max(5, int(liquidity * 0.5 * risk_factor)))
            max_trade_size = int(max_trade_size * (1 - abs(current_position) / position_limit))

            if current_position < max_trade_size and best_ask and best_ask < voucher_value - spread / 2:
                qty_to_buy = min(best_ask_qty, max_trade_size - current_position)
                if qty_to_buy > 0:
                    orders.append(Order(voucher, best_ask, qty_to_buy))
            elif current_position < max_trade_size:
                qty_to_buy = min(10, max_trade_size - current_position)
                if qty_to_buy > 0:
                    orders.append(Order(voucher, our_bid, qty_to_buy))

            if current_position > -max_trade_size and best_bid and best_bid > voucher_value + spread / 2:
                qty_to_sell = min(best_bid_qty, current_position + max_trade_size)
                if qty_to_sell > 0:
                    orders.append(Order(voucher, best_bid, -qty_to_sell))
            elif current_position > -max_trade_size:
                qty_to_sell = min(10, current_position + max_trade_size)
                if qty_to_sell > 0:
                    orders.append(Order(voucher, our_ask, -qty_to_sell))

            if rock_price and orders:
                delta = self.calculate_delta(voucher, rock_price)
                rock_orders = self.hedge_position(voucher, delta, state)
                if rock_orders:
                    result.setdefault("VOLCANIC_ROCK", []).extend(rock_orders)

            if orders:
                result[voucher] = orders

        if "VOLCANIC_ROCK" in state.order_depths:
            product = "VOLCANIC_ROCK"
            order_depth = state.order_depths[product]
            orders = []
            current_position = self.positions[product]
            position_limit = self.position_limits[product]
            fair_value = self.fair_values.get(product, None)
            
            if fair_value is not None:
                buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
                sell_orders = sorted(order_depth.sell_orders.items())
                
                if not (buy_orders and sell_orders):
                    return result, conversions, trader_data
                    
                best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
                best_bid_qty = buy_orders[0][1]
                best_ask_qty = sell_orders[0][1]

                volatility = self.volatility.get(product, 0.2)
                spread = max(2, int(1 + volatility * 500 * risk_factor))
                our_bid = int(fair_value - spread)
                our_ask = int(fair_value + spread)

                total_bid_volume = sum(qty for _, qty in buy_orders[:3])
                total_ask_volume = sum(qty for _, qty in sell_orders[:3])
                liquidity = min(total_bid_volume, total_ask_volume)
                max_trade_size = min(position_limit, max(10, int(liquidity * 0.5 * risk_factor)))
                max_trade_size = int(max_trade_size * (1 - abs(current_position) / position_limit))

                if current_position < max_trade_size and best_ask and best_ask < fair_value - spread / 2:
                    qty_to_buy = min(best_ask_qty, max_trade_size - current_position)
                    if qty_to_buy > 0:
                        orders.append(Order(product, best_ask, qty_to_buy))
                elif current_position < max_trade_size:
                    qty_to_buy = min(20, max_trade_size - current_position)
                    if qty_to_buy > 0:
                        orders.append(Order(product, our_bid, qty_to_buy))

                if current_position > -max_trade_size and best_bid and best_bid > fair_value + spread / 2:
                    qty_to_sell = min(best_bid_qty, current_position + max_trade_size)
                    if qty_to_sell > 0:
                        orders.append(Order(product, best_bid, -qty_to_sell))
                elif current_position > -max_trade_size:
                    qty_to_sell = min(20, current_position + max_trade_size)
                    if qty_to_sell > 0:
                        orders.append(Order(product, our_ask, -qty_to_sell))

                if orders:
                    result[product] = orders

        return result, conversions, trader_data

def simulate_trading(data):
    trader = Trader()
    total_pnl = 0
    state = TradingState("", 0, {}, {}, {}, {}, {}, {})
    last_prices = {product: None for product in trader.position_limits}

    for index, row in data.iterrows():
        timestamp = row["timestamp"]
        product = row["product"]
        
        order_depth = OrderDepth()
        for i in range(1, 4):
            bid_price = row.get(f"bid_price_{i}", None)
            bid_vol = row.get(f"bid_volume_{i}", 0)
            ask_price = row.get(f"ask_price_{i}", None)
            ask_vol = row.get(f"ask_volume_{i}", 0)
            if pd.notna(bid_price) and bid_price is not None:
                order_depth.buy_orders[int(bid_price)] = int(bid_vol)
            if pd.notna(ask_price) and ask_price is not None:
                order_depth.sell_orders[int(ask_price)] = int(ask_vol)
        
        state.order_depths[product] = order_depth
        state.timestamp = timestamp
        state.position = trader.positions.copy()
        last_prices[product] = row["mid_price"]

        result, _, _ = trader.run(state)

        for product, orders in result.items():
            for order in orders:
                price = order.price
                qty = order.quantity
                if qty > 0:  # Buy
                    trader.positions[product] += qty
                    trader.cumulative_pnl -= price * qty
                    total_pnl -= price * qty
                else:  # Sell
                    trader.positions[product] += qty
                    trader.cumulative_pnl -= price * qty
                    total_pnl -= price * qty

    unrealized_pnl = 0
    for product, position in trader.positions.items():
        if position != 0 and last_prices[product] is not None:
            unrealized_pnl += position * last_prices[product]

    total_pnl += unrealized_pnl
    return total_pnl, trader.positions

if __name__ == "__main__":
    try:
        data_str = """(your data here)"""  # Replace with the full document text
        from io import StringIO
        data = pd.read_csv(StringIO(data_str), sep=";")
        profit, final_positions = simulate_trading(data)
        print(f"Simulated Profit: {profit:.2f} SEASHELLS")
        print(f"Final Positions: {final_positions}")
    except Exception as e:
        print(f"Error loading data: {e}")