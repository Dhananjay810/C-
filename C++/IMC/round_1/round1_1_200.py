from datamodel import OrderDepth, TradingState, Order
from typing import Dict, List
import json
import numpy as np

class Trader:
    def __init__(self):
        self.position_limits = {
            "RAINFOREST_RESIN": 50,
            "KELP": 50,
            "SQUID_INK": 50
        }
        self.max_orders = 2000
        self.window_short = 10
        self.window_long = 50
        self.resin_window = 100
        self.min_profit_base = 2
        self.trade_size_base = 5
        self.products = ["RAINFOREST_RESIN", "KELP", "SQUID_INK"]
        self.squid_pattern_length = 15
        self.max_drawdown = 1000
        self.max_price_history = 1000  # Limit price history to prevent memory/timeout issues

    def calculate_moving_averages(self, prices: List[float]) -> tuple[float, float]:
        if len(prices) < self.window_long:
            return None, None
        short_ma = np.mean(prices[-self.window_short:])
        long_ma = np.mean(prices[-self.window_long:])
        return short_ma, long_ma

    def calculate_volatility(self, prices: List[float], window: int) -> float:
        if len(prices) < window:
            return 0.0
        return np.std(prices[-window:])

    def calculate_dynamic_mean(self, prices: List[float], window: int) -> float:
        if len(prices) < window:
            return 10000.0
        return np.mean(prices[-window:])

    def detect_squid_pattern(self, prices: List[float]) -> str:
        if len(prices) < self.squid_pattern_length:
            return "no_pattern"
        recent = prices[-self.squid_pattern_length:]
        changes = [recent[i] - recent[i-1] for i in range(1, len(recent))]
        if all(c >= 0 for c in changes):
            return "strong_upward"
        elif all(c <= 0 for c in changes):
            return "strong_downward"
        elif all(changes[i] * changes[i+1] < 0 for i in range(len(changes)-1)):
            return "mean_reverting"
        return "no_pattern"

    def run(self, state: TradingState) -> tuple[Dict[str, List[Order]], int, str]:
        result = {}
        conversions = 0

        # Load or initialize state
        if state.traderData:
            try:
                trader_data = json.loads(state.traderData)
                prices = trader_data.get("prices", {p: [] for p in self.products})
                total_orders = trader_data.get("total_orders", 0)
                avg_prices = trader_data.get("avg_prices", {p: {"buy": 0, "sell": 0} for p in self.products})
                volatilities = trader_data.get("volatilities", {p: 0 for p in self.products})
                last_pnl = trader_data.get("last_pnl", 0.0)
            except json.JSONDecodeError:
                prices = {p: [] for p in self.products}
                total_orders = 0
                avg_prices = {p: {"buy": 0, "sell": 0} for p in self.products}
                volatilities = {p: 0 for p in self.products}
                last_pnl = 0.0
        else:
            prices = {p: [] for p in self.products}
            total_orders = 0
            avg_prices = {p: {"buy": 0, "sell": 0} for p in self.products}
            volatilities = {p: 0 for p in self.products}
            last_pnl = 0.0

        current_positions = {p: state.position.get(p, 0) for p in self.products}

        # Update price history with limit
        if not hasattr(state, 'order_depths') or state.order_depths is None:
            trader_data = {
                "prices": prices,
                "total_orders": total_orders,
                "avg_prices": avg_prices,
                "volatilities": volatilities,
                "last_pnl": last_pnl
            }
            return {}, 0, json.dumps(trader_data)

        for product in self.products:
            if product in state.order_depths:
                order_depth = state.order_depths[product]
                if order_depth.buy_orders and order_depth.sell_orders:
                    best_bid = max(order_depth.buy_orders.keys())
                    best_ask = min(order_depth.sell_orders.keys())
                    mid_price = (best_bid + best_ask) / 2
                    prices[product].append(mid_price)
                    if len(prices[product]) > self.max_price_history:  # Trim history
                        prices[product] = prices[product][-self.max_price_history:]
                    volatilities[product] = self.calculate_volatility(prices[product], 20)

        # Trading logic
        for product in self.products:
            if product not in state.order_depths or total_orders >= self.max_orders:
                continue

            order_depth = state.order_depths[product]
            current_pos = current_positions[product]
            orders = []

            best_bid = max(order_depth.buy_orders.keys()) if order_depth.buy_orders else float('-inf')
            best_ask = min(order_depth.sell_orders.keys()) if order_depth.sell_orders else float('inf')
            bid_vol = order_depth.buy_orders.get(best_bid, 0) if order_depth.buy_orders else 0
            ask_vol = -order_depth.sell_orders.get(best_ask, 0) if order_depth.sell_orders else 0

            if best_bid == float('-inf') or best_ask == float('inf'):
                continue

            room_to_buy = self.position_limits[product] - current_pos
            room_to_sell = self.position_limits[product] + current_pos
            remaining_orders = self.max_orders - total_orders

            dynamic_min_profit = max(self.min_profit_base, volatilities[product] * 0.5)
            dynamic_trade_size = max(1, min(self.trade_size_base, int(volatilities[product] * 10)))

            if product == "KELP":
                short_ma, long_ma = self.calculate_moving_averages(prices[product])
                if short_ma is not None and long_ma is not None and volatilities[product] > 0.05:
                    if short_ma < long_ma and room_to_sell >= dynamic_trade_size:
                        sell_vol = min(dynamic_trade_size, bid_vol, room_to_sell, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = (avg_prices[product]["sell"] * abs(current_pos) + best_bid * sell_vol) / (abs(current_pos) + sell_vol) if current_pos - sell_vol < 0 else best_bid
                    if current_pos < 0 and best_ask <= avg_prices[product]["sell"] - dynamic_min_profit:
                        buy_vol = min(dynamic_trade_size, -current_pos, ask_vol, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = 0 if current_pos + buy_vol == 0 else avg_prices[product]["sell"]

            elif product == "RAINFOREST_RESIN":
                dynamic_mean = self.calculate_dynamic_mean(prices[product], self.resin_window)
                if best_ask <= dynamic_mean - dynamic_min_profit and room_to_buy >= dynamic_trade_size:
                    buy_vol = min(dynamic_trade_size, ask_vol, room_to_buy, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = (avg_prices[product]["buy"] * current_pos + best_ask * buy_vol) / (current_pos + buy_vol) if current_pos + buy_vol != 0 else best_ask
                if best_bid >= dynamic_mean + dynamic_min_profit and room_to_sell >= dynamic_trade_size:
                    sell_vol = min(dynamic_trade_size, bid_vol, room_to_sell, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = 0 if current_pos - sell_vol == 0 else avg_prices[product]["buy"]
                if current_pos > 0 and best_bid >= avg_prices[product]["buy"] + dynamic_min_profit:
                    sell_vol = min(dynamic_trade_size, current_pos, bid_vol, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = 0 if current_pos - sell_vol == 0 else avg_prices[product]["buy"]

            elif product == "SQUID_INK":
                pattern = self.detect_squid_pattern(prices[product])
                if pattern == "strong_upward" and room_to_buy >= dynamic_trade_size:
                    buy_vol = min(dynamic_trade_size, ask_vol, room_to_buy, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = (avg_prices[product]["buy"] * current_pos + best_ask * buy_vol) / (current_pos + buy_vol) if current_pos + buy_vol != 0 else best_ask
                elif pattern == "strong_downward" and room_to_sell >= dynamic_trade_size:
                    sell_vol = min(dynamic_trade_size, bid_vol, room_to_sell, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["sell"] = (avg_prices[product]["sell"] * abs(current_pos) + best_bid * sell_vol) / (abs(current_pos) + sell_vol) if current_pos - sell_vol < 0 else best_bid
                elif pattern == "mean_reverting":
                    mid_price = np.mean(prices[product][-self.squid_pattern_length:])
                    if best_ask <= mid_price - dynamic_min_profit and room_to_buy >= dynamic_trade_size:
                        buy_vol = min(dynamic_trade_size, ask_vol, room_to_buy, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["buy"] = (avg_prices[product]["buy"] * current_pos + best_ask * buy_vol) / (current_pos + buy_vol) if current_pos + buy_vol != 0 else best_ask
                    if best_bid >= mid_price + dynamic_min_profit and room_to_sell >= dynamic_trade_size:
                        sell_vol = min(dynamic_trade_size, bid_vol, room_to_sell, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = (avg_prices[product]["sell"] * abs(current_pos) + best_bid * sell_vol) / (abs(current_pos) + sell_vol) if current_pos - sell_vol < 0 else best_bid
                if current_pos > 0 and best_bid >= avg_prices[product]["buy"] + dynamic_min_profit:
                    sell_vol = min(dynamic_trade_size, current_pos, bid_vol, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = 0 if current_pos - sell_vol == 0 else avg_prices[product]["buy"]
                if current_pos < 0 and best_ask <= avg_prices[product]["sell"] - dynamic_min_profit:
                    buy_vol = min(dynamic_trade_size, -current_pos, ask_vol, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["sell"] = 0 if current_pos + buy_vol == 0 else avg_prices[product]["sell"]

            if orders:
                result[product] = orders

        # Save state
        trader_data = {
            "prices": prices,
            "total_orders": total_orders,
            "avg_prices": avg_prices,
            "volatilities": volatilities,
            "last_pnl": last_pnl
        }
        trader_data_str = json.dumps(trader_data)

        return result, conversions, trader_data_str