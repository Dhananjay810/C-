from typing import Dict, List, Tuple, Deque
from datamodel import OrderDepth, TradingState, Order
import pandas as pd
import numpy as np
from collections import deque
from statistics import mean

class Trader:
    def __init__(self):
        self.position_limits = {
            "SQUID_INK": 50, "PICNIC_BASKET1": 50, "PICNIC_BASKET2": 50,
            "RAINFOREST_RESIN": 50, "KELP": 50, "CROISSANTS": 50,
            "JAMS": 50, "DJEMBES": 50
        }
        self.positions = {product: 0 for product in self.position_limits}
        self.fair_values = {product: None for product in self.position_limits}
        self.price_history = {product: deque(maxlen=50) for product in self.position_limits}
        self.entry_prices = {product: None for product in self.position_limits}
        self.highest_prices = {product: None for product in self.position_limits}
        self.lowest_prices = {product: None for product in self.position_limits}
        
        self.params = {
            "market_making": {
                "base_spread": 2.0,  # Bigger spread for profit
                "min_profit": 1.0
            },
            "trend_following": {
                "momentum_window": 5,
                "threshold": 0.0005  # Catch trends early
            },
            "risk_management": {
                "max_position_risk": 0.4,  # 20 units max
                "stop_loss_pct": 0.10,
                "take_profit_pct": 0.12,
                "trailing_stop_pct": 0.07
            }
        }

    def update_fair_value(self, product: str, state: TradingState):
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        if buy_orders and sell_orders:
            best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
            fair_value = (best_bid + best_ask) / 2
            self.fair_values[product] = fair_value
            self.price_history[product].append(fair_value)
            if self.positions[product] > 0:
                self.highest_prices[product] = max(self.highest_prices[product] or fair_value, fair_value)
            elif self.positions[product] < 0:
                self.lowest_prices[product] = min(self.lowest_prices[product] or fair_value, fair_value)

    def detect_trend(self, product: str) -> Tuple[float, str]:
        prices = list(self.price_history[product])
        if len(prices) < self.params["trend_following"]["momentum_window"]:
            return 0.0, "neutral"
        
        momentum_ma = mean(prices[-self.params["trend_following"]["momentum_window"]:])
        current_price = prices[-1]
        prev_price = prices[-2] if len(prices) > 1 else current_price
        momentum = (current_price - prev_price) / prev_price if prev_price != 0 else 0.0
        threshold = self.params["trend_following"]["threshold"]
        
        if momentum > threshold and current_price > momentum_ma:
            return momentum, "uptrend"
        elif momentum < -threshold and current_price < momentum_ma:
            return momentum, "downtrend"
        return 0.0, "neutral"

    def calculate_order_size(self, product: str, current_position: int) -> int:
        position_limit = self.position_limits[product]
        max_risk_size = int(position_limit * self.params["risk_management"]["max_position_risk"])
        available = max_risk_size - abs(current_position)
        if product == "KELP":
            return min(10, available)  # Tiny for KELP
        return min(20, available)

    def run(self, state: TradingState) -> Tuple[Dict[str, List[Order]], int, str]:
        result = {}
        conversions = 0
        trader_data = ""

        for product in self.positions:
            self.positions[product] = state.position.get(product, 0)

        for product in state.order_depths:
            self.update_fair_value(product, state)

        for product in state.order_depths:
            if product in ["DJEMBES", "PICNIC_BASKET2", "RAINFOREST_RESIN"]:
                continue
                
            order_depth = state.order_depths[product]
            orders = []
            current_position = self.positions[product]
            position_limit = self.position_limits[product]
            fair_value = self.fair_values.get(product, None)

            if fair_value is None or not order_depth.buy_orders or not order_depth.sell_orders:
                continue

            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            best_bid = buy_orders[0][0]
            best_ask = sell_orders[0][0]
            best_bid_qty = buy_orders[0][1]
            best_ask_qty = sell_orders[0][1]

            order_size = self.calculate_order_size(product, current_position)
            target_bid = max(1, int(fair_value - self.params["market_making"]["base_spread"]))
            target_ask = max(1, int(fair_value + self.params["market_making"]["base_spread"]))

            # Trend Following for SQUID_INK and PICNIC_BASKET1
            if product in ["SQUID_INK", "PICNIC_BASKET1"]:
                momentum, trend_direction = self.detect_trend(product)
                if trend_direction == "uptrend" and current_position < position_limit:
                    buy_price = max(1, int(best_ask))
                    buy_qty = min(order_size, best_ask_qty, position_limit - current_position)
                    if buy_qty > 0:
                        orders.append(Order(product, buy_price, buy_qty))
                        self.entry_prices[product] = buy_price if self.entry_prices[product] is None else self.entry_prices[product]
                        self.highest_prices[product] = buy_price
                elif trend_direction == "downtrend" and current_position > -position_limit:
                    sell_price = max(1, int(best_bid))
                    sell_qty = min(order_size, best_bid_qty, position_limit + current_position)
                    if sell_qty > 0:
                        orders.append(Order(product, sell_price, -sell_qty))
                        self.entry_prices[product] = sell_price if self.entry_prices[product] is None else self.entry_prices[product]
                        self.lowest_prices[product] = sell_price

            # Market Making for CROISSANTS, JAMS, KELP
            if product in ["CROISSANTS", "JAMS", "KELP"] and not orders:
                momentum, trend_direction = self.detect_trend(product)
                if trend_direction == "downtrend":
                    bid_qty = min(order_size, position_limit - current_position, best_bid_qty)
                    if bid_qty > 0:
                        orders.append(Order(product, target_bid, bid_qty))
                elif trend_direction == "uptrend":
                    ask_qty = min(order_size, position_limit + current_position, best_ask_qty)
                    if ask_qty > 0:
                        orders.append(Order(product, target_ask, -ask_qty))
                else:
                    bid_qty = min(order_size, position_limit - current_position, best_bid_qty)
                    ask_qty = min(order_size, position_limit + current_position, best_ask_qty)
                    if bid_qty > 0:
                        orders.append(Order(product, target_bid, bid_qty))
                    if ask_qty > 0:
                        orders.append(Order(product, target_ask, -ask_qty))

            # Risk Management
            if current_position != 0 and self.entry_prices[product] is not None:
                entry_price = self.entry_prices[product]
                if current_position > 0:  # Long
                    stop_loss = entry_price * (1 - self.params["risk_management"]["stop_loss_pct"])
                    take_profit = entry_price * (1 + self.params["risk_management"]["take_profit_pct"])
                    trailing_stop = self.highest_prices[product] * (1 - self.params["risk_management"]["trailing_stop_pct"])
                    if best_bid <= min(stop_loss, trailing_stop) or best_bid >= take_profit:
                        close_qty = min(abs(current_position), best_bid_qty)
                        if close_qty > 0:
                            orders.append(Order(product, best_bid, -close_qty))
                            self.entry_prices[product] = None
                            self.highest_prices[product] = None
                elif current_position < 0:  # Short
                    stop_loss = entry_price * (1 + self.params["risk_management"]["stop_loss_pct"])
                    take_profit = entry_price * (1 - self.params["risk_management"]["take_profit_pct"])
                    trailing_stop = self.lowest_prices[product] * (1 + self.params["risk_management"]["trailing_stop_pct"])
                    if best_ask >= max(stop_loss, trailing_stop) or best_ask <= take_profit:
                        close_qty = min(abs(current_position), best_ask_qty)
                        if close_qty > 0:
                            orders.append(Order(product, best_ask, close_qty))
                            self.entry_prices[product] = None
                            self.lowest_prices[product] = None

            if orders:
                result[product] = orders

        return result, conversions, trader_data

def simulate_trading(data):
    trader = Trader()
    total_pnl = 0
    state = TradingState("", 0, {}, {}, {}, {}, {}, {})
    last_prices = {product: None for product in trader.position_limits}
    trades = []

    for index, row in data.iterrows():
        timestamp = row["timestamp"]
        product = row["product"]
        
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

        result, _, _ = trader.run(state)

        for product, orders in result.items():
            for order in orders:
                price = order.price
                qty = order.quantity
                if qty > 0:  # Buy
                    trader.positions[product] += qty
                    total_pnl -= price * qty
                    trades.append((timestamp, product, "buy", price, qty, total_pnl))
                else:  # Sell
                    trader.positions[product] += qty
                    total_pnl += price * abs(qty)
                    trades.append((timestamp, product, "sell", price, abs(qty), total_pnl))

    unrealized_pnl = sum(pos * price for pos, price in zip(trader.positions.values(), [last_prices[p] for p in trader.position_limits]) if price is not None)
    total_pnl += unrealized_pnl
    return total_pnl, trader.positions, trades

if __name__ == "__main__":
    data = pd.read_csv("data_1.csv", sep=";")
    profit, final_positions, trades = simulate_trading(data)
    print(f"Simulated Profit: {profit:.2f} SEASHELLS")
    print(f"Final Positions: {final_positions}")
    print("Last 10 trades for debugging:")
    for trade in trades[-10:]:
        print(f"Timestamp: {trade[0]}, Product: {trade[1]}, Action: {trade[2]}, Price: {trade[3]}, Qty: {trade[4]}, PNL: {trade[5]:.2f}")