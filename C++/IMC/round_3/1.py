from typing import Dict, List
from datamodel import OrderDepth, TradingState, Order
import pandas as pd

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

    def update_fair_value(self, product: str, state: TradingState):
        if product not in state.order_depths:
            return
            
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        
        if buy_orders and sell_orders:
            best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
            self.fair_values[product] = (best_bid + best_ask) / 2

    def calculate_voucher_value(self, voucher: str, rock_price: float) -> float:
        """Calculate theoretical value of voucher based on underlying rock price"""
        if rock_price is None:
            return None
            
        strike = self.voucher_details[voucher]["strike"]
        days_left = self.voucher_details[voucher]["days_left"]
        
        # Simple intrinsic value calculation (could be enhanced with time value)
        intrinsic_value = max(0, rock_price - strike)
        
        # Discount for time remaining (linear discount for simplicity)
        time_factor = days_left / 7  # Full value at day 7, zero at expiration
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
            if voucher in self.voucher_details:
                self.voucher_details[voucher]["days_left"] = max(0, 7 - self.round + 1)

        # Update fair values for all products
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

            # Market making for vouchers
            spread = 2  # Small spread for market making
            our_bid = max(1, int(voucher_value - spread))
            our_ask = int(voucher_value + spread)

            # Post bids (buy orders)
            if current_position < position_limit and best_ask and our_bid >= best_ask:
                qty_to_buy = min(best_ask_qty, position_limit - current_position)
                if qty_to_buy > 0:
                    orders.append(Order(voucher, best_ask, qty_to_buy))
            elif current_position < position_limit:
                # Post our bid if we have room
                orders.append(Order(voucher, our_bid, position_limit - current_position))

            # Post asks (sell orders)
            if current_position > -position_limit and best_bid and our_ask <= best_bid:
                qty_to_sell = min(best_bid_qty, current_position + position_limit)
                if qty_to_sell > 0:
                    orders.append(Order(voucher, best_bid, -qty_to_sell))
            elif current_position > -position_limit:
                # Post our ask if we have room
                orders.append(Order(voucher, our_ask, -(position_limit + current_position)))

            if orders:
                result[voucher] = orders

        # Also trade the underlying volcanic rock
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

                # Simple market making for volcanic rock
                if current_position < position_limit and best_ask:
                    qty_to_buy = min(best_ask_qty, position_limit - current_position)
                    if qty_to_buy > 0:
                        orders.append(Order(product, best_ask, qty_to_buy))

                if current_position > -position_limit and best_bid:
                    qty_to_sell = min(best_bid_qty, current_position + position_limit)
                    if qty_to_sell > 0:
                        orders.append(Order(product, best_bid, -qty_to_sell))

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