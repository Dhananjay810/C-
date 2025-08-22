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
            "VOLCANIC_ROCK_VOUCHER_10500": 200, "MAGNIFICENT_MACARONS": 75
        }
        self.conversion_limits = {
            "MAGNIFICENT_MACARONS": 10
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
        self.macaron_factors = {
            "hours_sunlight": 12,  # Assume average 12 hours
            "sugar_price": 100,    # Base price in SEASHELLS per unit
            "shipping_cost": 10,   # Per unit
            "tariff_rate": 0.05,   # 5% import/export tariff
            "storage_cost": 2      # Per unit per round
        }
        self.round = 0
        self.macaron_conversion_count = 0
        self.pnl = 0  # Track cumulative PnL
        self.trade_log = []  # Log trades for debugging

    def update_fair_value(self, product: str, state: TradingState):
        if product not in state.order_depths:
            return
            
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        
        if buy_orders and sell_orders:
            best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
            self.fair_values[product] = (best_bid + best_ask) / 2

    def calculate_macaron_value(self, state: TradingState) -> float:
        """Calculate theoretical value of MAGNIFICENT_MACARONS with market feedback"""
        base_value = 1000  # Base price in SEASHELLS
        
        # Adjust for sunlight hours (more sunlight improves quality)
        sunlight_factor = self.macaron_factors["hours_sunlight"] / 12
        value = base_value * max(0.9, min(1.1, sunlight_factor))  # ±10% impact
        
        # Adjust for sugar price
        sugar_factor = self.macaron_factors["sugar_price"] / 100
        value *= max(0.95, min(1.15, sugar_factor))  # ±15% impact
        
        # Add shipping costs and tariffs
        value += self.macaron_factors["shipping_cost"]
        value *= (1 + self.macaron_factors["tariff_rate"])
        
        # Add storage costs
        value += self.macaron_factors["storage_cost"] * self.round
        
        # Incorporate market feedback (order book mid-price)
        if "MAGNIFICENT_MACARONS" in state.order_depths:
            order_depth = state.order_depths["MAGNIFICENT_MACARONS"]
            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            if buy_orders and sell_orders:
                market_mid = (buy_orders[0][0] + sell_orders[0][0]) / 2
                # Blend theoretical value with market mid-price (50-50 weight)
                value = 0.5 * value + 0.5 * market_mid
        
        return max(1, value)  # Ensure positive value

    def calculate_voucher_value(self, voucher: str, rock_price: float) -> float:
        """Calculate theoretical value of voucher based on underlying rock price"""
        if rock_price is None:
            return None
            
        strike = self.voucher_details[voucher]["strike"]
        days_left = self.voucher_details[voucher]["days_left"]
        
        intrinsic_value = max(0, rock_price - strike)
        time_factor = days_left / 7
        return intrinsic_value * time_factor

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
            self.voucher_details[voucher]["days_left"] = max(0, 7 - self.round + 1)

        # Update fair values
        for product in state.order_depths:
            self.update_fair_value(product, state)

        rock_price = self.fair_values.get("VOLCANIC_ROCK", None)

        # Trade MAGNIFICENT_MACARONS
        if "MAGNIFICENT_MACARONS" in state.order_depths:
            product = "MAGNIFICENT_MACARONS"
            order_depth = state.order_depths[product]
            orders = []
            current_position = self.positions[product]
            position_limit = self.position_limits[product]
            macaron_value = self.calculate_macaron_value(state)
            
            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            best_bid = buy_orders[0][0] if buy_orders else None
            best_ask = sell_orders[0][0] if sellfirst_ask_qty = sell_orders[0][1] if sell_orders else 0

            # Tighter spread for market making
            spread = 2
            our_bid = max(1, int(macaron_value - spread))
            our_ask = int(macaron_value + spread)

            # Limit order size to manage risk
            max_trade_size = 10  # Cap individual trade size
            available_position = position_limit - abs(current_position)

            # Buy logic: only take undervalued opportunities
            if current_position < position_limit and best_ask and best_ask <= our_bid:
                qty_to_buy = min(best_ask_qty, available_position, max_trade_size)
                if qty_to_buy > 0:
                    orders.append(Order(product, best_ask, qty_to_buy))
                    self.trade_log.append(f"Round {self.round}: Buy {qty_to_buy} {product} at {best_ask}")
            elif current_position < position_limit and available_position >= 5:
                qty_to_buy = min(available_position, max_trade_size)
                orders.append(Order(product, our_bid, qty_to_buy))
                self.trade_log.append(f"Round {self.round}: Post bid for {qty_to_buy} {product} at {our_bid}")

            # Sell logic: only take overvalued opportunities
            if current_position > -position_limit and best_bid and best_bid >= our_ask:
                qty_to_sell = min(best_bid_qty, available_position, max_trade_size)
                if qty_to_sell > 0:
                    orders.append(Order(product, best_bid, -qty_to_sell))
                    self.trade_log.append(f"Round {self.round}: Sell {qty_to_sell} {product} at {best_bid}")
            elif current_position > -position_limit and available_position >= 5:
                qty_to_sell = min(available_position, max_trade_size)
                orders.append(Order(product, our_ask, -qty_to_sell))
                self.trade_log.append(f"Round {self.round}: Post ask for {qty_to_sell} {product} at {our_ask}")

            # Conversion logic: only if significant mispricing
            if self.macaron_conversion_count < self.conversion_limits["MAGNIFICENT_MACARONS"]:
                if current_position > 0 and best_bid and best_bid > macaron_value + 15:
                    conversions = min(current_position, 
                                    self.conversion_limits["MAGNIFICENT_MACARONS"] - self.macaron_conversion_count)
                    self.macaron_conversion_count += conversions
                    self.trade_log.append(f"Round {self.round}: Convert {conversions} {product} at {best_bid}")
                elif current_position < 0 and best_ask and best_ask < macaron_value - 15:
                    conversions = min(-current_position, 
                                    self.conversion_limits["MAGNIFICENT_MACARONS"] - self.macaron_conversion_count)
                    self.macaron_conversion_count += conversions
                    self.trade_log.append(f"Round {self.round}: Convert {conversions} {product} at {best_ask}")

            if orders:
                result[product] = orders

        # Trade vouchers
        for voucher in self.voucher_details:
            if voucher not in state.order_depths:
                continue
                
            order_depth = state.order_depths[voucher]
            current_position = self.positions[voucher]
            position_limit = self.position_limits[voucher]
            orders = []
            
            voucher_value = self.calculate_voucher_value(voucher, rock_price)
            if voucher_value is None:
                continue
                
            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            best_bid = buy_orders[0][0] if buy_orders else None
            best_ask = sell_orders[0][0] if sell_orders else None
            best_bid_qty = buy_orders[0][1] if buy_orders else 0
            best_ask_qty = sell_orders[0][1] if sell_orders else 0

            spread = 1
            our_bid = max(1, int(voucher_value - spread))
            our_ask = int(voucher_value + spread)
            max_trade_size = 20

            if current_position < position_limit and best_ask and best_ask <= our_bid:
                qty_to_buy = min(best_ask_qty, position_limit - current_position, max_trade_size)
                if qty_to_buy > 0:
                    orders.append(Order(voucher, best_ask, qty_to_buy))
                    self.trade_log.append(f"Round {self.round}: Buy {qty_to_buy} {voucher} at {best_ask}")
            elif current_position < position_limit:
                qty_to_buy = min(position_limit - current_position, max_trade_size)
                orders.append(Order(voucher, our_bid, qty_to_buy))
                self.trade_log.append(f"Round {self.round}: Post bid for {qty_to_buy} {voucher} at {our_bid}")

            if current_position > -position_limit and best_bid and best_bid >= our_ask:
                qty_to_sell = min(best_bid_qty, current_position + position_limit, max_trade_size)
                if qty_to_sell > 0:
                    orders.append(Order(voucher, best_bid, -qty_to_sell))
                    self.trade_log.append(f"Round {self.round}: Sell {qty_to_sell} {voucher} at {best_bid}")
            elif current_position > -position_limit:
                qty_to_sell = min(position_limit + current_position, max_trade_size)
                orders.append(Order(voucher, our_ask, -qty_to_sell))
                self.trade_log.append(f"Round {self.round}: Post ask for {qty_to_sell} {voucher} at {our_ask}")

            if orders:
                result[voucher] = orders

        # Trade VOLCANIC_ROCK
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
                best_bid = buy_orders[0][0] if buy_orders else None
                best_ask = sell_orders[0][0] if sell_orders else None
                best_bid_qty = buy_orders[0][1] if buy_orders else 0
                best_ask_qty = sell_orders[0][1] if sell_orders else 0

                max_trade_size = 50
                if current_position < position_limit and best_ask and best_ask <= fair_value:
                    qty_to_buy = min(best_ask_qty, position_limit - current_position, max_trade_size)
                    if qty_to_buy > 0:
                        orders.append(Order(product, best_ask, qty_to_buy))
                        self.trade_log.append(f"Round {self.round}: Buy {qty_to_buy} {product} at {best_ask}")

                if current_position > -position_limit and best_bid and best_bid >= fair_value:
                    qty_to_sell = min(best_bid_qty, current_position + position_limit, max_trade_size)
                    if qty_to_sell > 0:
                        orders.append(Order(product, best_bid, -qty_to_sell))
                        self.trade_log.append(f"Round {self.round}: Sell {qty_to_sell} {product} at {best_bid}")

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
        result, conversions, _ = trader.run(state)

        # Simulate trade execution and update PnL
        for product, orders in result.items():
            for order in orders:
                price = order.price
                qty = order.quantity
                if qty > 0:  # Buy
                    trader.positions[product] += qty
                    trader.pnl -= price * qty
                    total_pnl -= price * qty
                else:  # Sell
                    trader.positions[product] += qty
                    trader.pnl -= price * qty
                    total_pnl -= price * qty

        # Update positions and PnL for conversions
        if conversions > 0:
            trader.positions["MAGNIFICENT_MACARONS"] -= conversions
            conversion_value = last_prices["MAGNIFICENT_MACARONS"]
            trader.pnl += conversions * conversion_value
            total_pnl += conversions * conversion_value
            trader.trade_log.append(f"Round {trader.round}: Conversion PnL +{conversions * conversion_value}")

    # Calculate unrealized PnL
    unrealized_pnl = 0
    for product, position in trader.positions.items():
        if position != 0 and last_prices[product] is not None:
            unrealized_pnl += position * last_prices[product]
            trader.trade_log.append(f"Final: Unrealized PnL for {product}: {position * last_prices[product]}")

    total_pnl += unrealized_pnl
    trader.trade_log.append(f"Final Total PnL: {total_pnl}")

    # Print trade log for debugging
    for log in trader.trade_log[-10:]:  # Show last 10 logs
        print(log)

    return total_pnl, trader.positions

if __name__ == "__main__":
    # Load the provided data
    data_str = """(your data here)"""  # Replace with the full document text
    from io import StringIO
    data = pd.read_csv(StringIO(data_str), sep=";")
    profit, final_positions = simulate_trading(data)
    print(f"Simulated Profit: {profit:.2f} SEASHELLS")
    print(f"Final Positions: {final_positions}")