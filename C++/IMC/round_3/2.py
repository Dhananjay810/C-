from typing import Dict, List
from datamodel import OrderDepth, TradingState, Order
import pandas as pd
import numpy as np
from statistics import mean, stdev

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
        self.spread_history = {product: [] for product in self.position_limits}
        self.volatility = {product: 0 for product in self.position_limits}
        self.last_trades = {product: None for product in self.position_limits}

    def update_fair_value(self, product: str, state: TradingState):
        if product not in state.order_depths:
            return
            
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        
        if buy_orders and sell_orders:
            best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
            mid_price = (best_bid + best_ask) / 2
            self.fair_values[product] = mid_price
            self.price_history[product].append(mid_price)
            
            # Calculate spread
            spread = best_ask - best_bid
            self.spread_history[product].append(spread)
            
            # Update volatility (using rolling standard deviation)
            if len(self.price_history[product]) > 5:
                recent_prices = self.price_history[product][-5:]
                self.volatility[product] = stdev(recent_prices) if len(recent_prices) > 1 else 0

    def calculate_voucher_value(self, voucher: str, rock_price: float) -> float:
        """Enhanced voucher valuation with time decay and volatility"""
        if rock_price is None:
            return None
            
        strike = self.voucher_details[voucher]["strike"]
        days_left = self.voucher_details[voucher]["days_left"]
        
        # Intrinsic value
        intrinsic_value = max(0, rock_price - strike)
        
        # Time decay - exponential decay model
        time_factor = np.exp(-0.1 * (7 - days_left))  # More aggressive decay
        
        # Volatility premium (higher volatility increases option value)
        vol_premium = 0
        if self.volatility.get("VOLCANIC_ROCK", 0) > 100:  # Significant volatility
            vol_premium = self.volatility["VOLCANIC_ROCK"] * days_left / 1000
            
        return intrinsic_value * time_factor + vol_premium

    def calculate_aggression(self, product: str) -> float:
        """Determine how aggressively to trade based on market conditions"""
        if len(self.spread_history[product]) < 3:
            return 1.0
            
        # More aggressive when spreads are tight
        avg_spread = mean(self.spread_history[product][-3:])
        norm_spread = avg_spread / max(1, self.fair_values.get(product, 1))
        
        # More aggressive in high volatility
        vol_factor = min(2.0, 1 + self.volatility.get(product, 0)/200)
        
        # Base aggression between 0.5 and 1.5
        aggression = 1.5 - min(1.0, norm_spread * 0.01) * vol_factor
        return max(0.5, min(2.0, aggression))

    def run(self, state: TradingState) -> (Dict[str, List[Order]], int, str):
        self.round += 1
        result = {}
        conversions = 0
        trader_data = ""

        # Update positions
        for product in self.positions:
            self.positions[product] = state.position.get(product, 0)

        # Update days left for vouchers
        for voucher in self.voucher_details:
            if voucher in self.voucher_details:
                self.voucher_details[voucher]["days_left"] = max(0, 7 - self.round + 1)

        # Update fair values and market statistics for all products
        for product in state.order_depths:
            self.update_fair_value(product, state)

        # Get volcanic rock price if available
        rock_price = self.fair_values.get("VOLCANIC_ROCK", None)

        # Trade vouchers based on their theoretical value
        for voucher in self.voucher_details:
            if voucher not in state.order_depths:
                continue
                
            order_depth = state.order_depths[voucher]
            current_position = self.positions[voucher]
            position_limit = self.position_limits[voucher]
            orders = []
            
            # Calculate theoretical value
            voucher_value = self.calculate_voucher_value(voucher, rock_price)
            if voucher_value is None:
                continue
                
            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            best_bid = buy_orders[0][0] if buy_orders else None
            best_ask = sell_orders[0][0] if sell_orders else None
            best_bid_qty = buy_orders[0][1] if buy_orders else 0
            best_ask_qty = sell_orders[0][1] if sell_orders else 0

            # Dynamic spread based on volatility and position
            position_factor = 1 - abs(current_position) / position_limit
            volatility_factor = 1 + self.volatility.get(voucher, 0)/200
            base_spread = max(1, int(5 / volatility_factor * position_factor))
            
            # Calculate aggression factor
            aggression = self.calculate_aggression(voucher)
            
            # Adjusted market making prices
            our_bid = max(1, int(voucher_value - base_spread * aggression))
            our_ask = int(voucher_value + base_spread * aggression)

            # Post bids (buy orders) - more aggressive when undervalued
            if current_position < position_limit:
                if best_ask and our_bid >= best_ask:
                    # Take the best available offer
                    qty_to_buy = min(best_ask_qty, position_limit - current_position)
                    if qty_to_buy > 0:
                        orders.append(Order(voucher, best_ask, qty_to_buy))
                else:
                    # Post our bid if we have room
                    bid_qty = min(position_limit - current_position, 
                                max(5, int((position_limit - current_position) * aggression)))
                    orders.append(Order(voucher, our_bid, bid_qty))

            # Post asks (sell orders) - more aggressive when overvalued
            if current_position > -position_limit:
                if best_bid and our_ask <= best_bid:
                    # Hit the best available bid
                    qty_to_sell = min(best_bid_qty, current_position + position_limit)
                    if qty_to_sell > 0:
                        orders.append(Order(voucher, best_bid, -qty_to_sell))
                else:
                    # Post our ask if we have room
                    ask_qty = min(position_limit + current_position,
                                max(5, int((position_limit + current_position) * aggression)))
                    orders.append(Order(voucher, our_ask, -ask_qty))

            if orders:
                result[voucher] = orders

        # Enhanced volcanic rock trading with mean reversion
        if "VOLCANIC_ROCK" in state.order_depths:
            product = "VOLCANIC_ROCK"
            order_depth = state.order_depths[product]
            orders = []
            current_position = self.positions[product]
            position_limit = self.position_limits[product]
            fair_value = self.fair_values.get(product, None)
            
            if fair_value is not None and len(self.price_history[product]) > 5:
                # Mean reversion strategy
                recent_prices = self.price_history[product][-5:]
                short_term_ma = mean(recent_prices)
                price_deviation = (fair_value - short_term_ma) / short_term_ma
                
                buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
                sell_orders = sorted(order_depth.sell_orders.items())
                best_bid = buy_orders[0][0] if buy_orders else None
                best_ask = sell_orders[0][0] if sell_orders else None
                best_bid_qty = buy_orders[0][1] if buy_orders else 0
                best_ask_qty = sell_orders[0][1] if sell_orders else 0

                # Trade more aggressively when price deviates from mean
                mr_aggression = min(2.0, max(0.5, abs(price_deviation) * 100))
                
                if price_deviation < -0.01:  # Undervalued - buy more
                    if current_position < position_limit and best_ask:
                        qty_to_buy = min(best_ask_qty, 
                                       int((position_limit - current_position) * mr_aggression))
                        if qty_to_buy > 0:
                            orders.append(Order(product, best_ask, qty_to_buy))
                
                elif price_deviation > 0.01:  # Overvalued - sell more
                    if current_position > -position_limit and best_bid:
                        qty_to_sell = min(best_bid_qty,
                                        int((position_limit + current_position) * mr_aggression))
                        if qty_to_sell > 0:
                            orders.append(Order(product, best_bid, -qty_to_sell))

                if orders:
                    result[product] = orders

        # Pair trading between vouchers and underlying rock
        if rock_price is not None:
            for voucher in self.voucher_details:
                if voucher not in state.order_depths:
                    continue
                    
                voucher_price = self.fair_values.get(voucher)
                if voucher_price is None:
                    continue
                    
                theoretical_value = self.calculate_voucher_value(voucher, rock_price)
                if theoretical_value is None:
                    continue
                    
                mispricing = voucher_price - theoretical_value
                
                # Threshold for pair trading (1% of rock price)
                threshold = rock_price * 0.01
                
                if mispricing > threshold:  # Voucher overpriced
                    # Sell voucher and buy rock (if within limits)
                    voucher_pos = self.positions[voucher]
                    rock_pos = self.positions["VOLCANIC_ROCK"]
                    
                    if (voucher_pos > -self.position_limits[voucher] and 
                        rock_pos < self.position_limits["VOLCANIC_ROCK"]):
                        
                        qty = min(5, self.position_limits[voucher] + voucher_pos,
                                self.position_limits["VOLCANIC_ROCK"] - rock_pos)
                        
                        if qty > 0:
                            if voucher not in result:
                                result[voucher] = []
                            result[voucher].append(Order(voucher, voucher_price-1, -qty))
                            
                            if "VOLCANIC_ROCK" not in result:
                                result["VOLCANIC_ROCK"] = []
                            result["VOLCANIC_ROCK"].append(Order("VOLCANIC_ROCK", rock_price+1, qty))
                
                elif mispricing < -threshold:  # Voucher underpriced
                    # Buy voucher and sell rock (if within limits)
                    voucher_pos = self.positions[voucher]
                    rock_pos = self.positions["VOLCANIC_ROCK"]
                    
                    if (voucher_pos < self.position_limits[voucher] and 
                        rock_pos > -self.position_limits["VOLCANIC_ROCK"]):
                        
                        qty = min(5, self.position_limits[voucher] - voucher_pos,
                                self.position_limits["VOLCANIC_ROCK"] + rock_pos)
                        
                        if qty > 0:
                            if voucher not in result:
                                result[voucher] = []
                            result[voucher].append(Order(voucher, voucher_price+1, qty))
                            
                            if "VOLCANIC_ROCK" not in result:
                                result["VOLCANIC_ROCK"] = []
                            result["VOLCANIC_ROCK"].append(Order("VOLCANIC_ROCK", rock_price-1, -qty))

        return result, conversions, trader_data

def simulate_trading(data):
    trader = Trader()
    total_pnl = 0
    state = TradingState("", 0, {}, {}, {}, {}, {}, {})
    last_prices = {product: None for product in trader.position_limits}

    for index, row in data.iterrows():
        timestamp = row["timestamp"]
        product = row["product"]
        
        # Populate order_depths
        order_depth = OrderDepth()
        for i in range(1, 4):
            bid_price = row.get(f"bid_price_{i}", None)
            bid_vol = row.get(f"bid_volume_{i}", 0)
            ask_price = row.get(f"ask_price_{i}", None)
            ask_vol = row.get(f"ask_volume_{i}", 0)
            if pd.notna(bid_price):
                order_depth.buy_orders[int(bid_price)] = int(bid_vol)
            if pd.notna(ask_price):
                order_depth.sell_orders[int(ask_price)] = int(ask_vol)
        
        state.order_depths[product] = order_depth
        state.timestamp = timestamp
        state.position = trader.positions.copy()
        last_prices[product] = row["mid_price"]

        # Run trader
        result, _, _ = trader.run(state)

        # Simulate trade execution and update PnL
        for product, orders in result.items():
            for order in orders:
                price = order.price
                qty = order.quantity
                if qty > 0:  # Buy
                    trader.positions[product] += qty
                    total_pnl -= price * qty  # Cash outflow
                else:  # Sell
                    trader.positions[product] += qty  # qty is negative
                    total_pnl -= price * qty  # Cash inflow (qty negative)

    # Calculate unrealized PnL for final positions
    unrealized_pnl = 0
    for product, position in trader.positions.items():
        if position != 0 and last_prices[product] is not None:
            unrealized_pnl += position * last_prices[product]

    total_pnl += unrealized_pnl
    return total_pnl, trader.positions

if __name__ == "__main__":
    # Load the provided data
    data_str = """(your data here)"""  # Replace with the full document text
    from io import StringIO
    data = pd.read_csv(StringIO(data_str), sep=";")
    profit, final_positions = simulate_trading(data)
    print(f"Simulated Profit: {profit:.2f} SEASHELLS")
    print(f"Final Positions: {final_positions}")