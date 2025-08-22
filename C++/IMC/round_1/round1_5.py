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
        self.max_orders = 2500  # Increased to allow more trades
        self.window_short = 3   # Reduced for faster response
        self.window_long = 15   # Adjusted for better trend capture
        self.min_profit = 1     # Lowered to capture more trades
        self.base_trade_size = 5  # Base trade size
        self.volatility_factor = 0.5  # For dynamic trade sizing
        self.products = ["RAINFOREST_RESIN", "KELP", "SQUID_INK"]
        self.squid_pattern_length = 8  # Reduced for quicker pattern detection
        self.price_history = {p: [] for p in self.products}  # Track prices
        self.last_mid_prices = {p: 0 for p in self.products}  # Track last mid prices
    
    def calculate_volatility(self, prices: List[float]) -> float:
        if len(prices) < 2:
            return 0
        return np.std(prices[-10:]) if len(prices) >= 10 else 0

    def calculate_dynamic_mean(self, prices: List[float]) -> float:
        if not prices:
            return 10000  # Default for RAINFOREST_RESIN
        return np.mean(prices[-20:])  # Dynamic mean based on recent prices

    def calculate_moving_averages(self, prices: List[float]) -> tuple[float, float]:
        if len(prices) < self.window_long:
            return None, None
        short_ma = np.mean(prices[-self.window_short:])
        long_ma = np.mean(prices[-self.window_long:])
        return short_ma, long_ma

    def detect_squid_pattern(self, prices: List[float]) -> str:
        if len(prices) < self.squid_pattern_length:
            return "no_pattern"
        
        recent = prices[-self.squid_pattern_length:]
        changes = [recent[i] - recent[i-1] for i in range(1, len(recent))]
        
        # Stronger trend detection
        if all(c > 0 for c in changes) and np.mean(changes) > self.calculate_volatility(prices):
            return "strong_upward"
        elif all(c < 0 for c in changes) and abs(np.mean(changes)) > self.calculate_volatility(prices):
            return "strong_downward"
        elif sum(1 for i in range(len(changes)-1) if changes[i] * changes[i+1] < 0) > len(changes) * 0.7:
            return "mean_reverting"
        else:
            return "no_pattern"

    def adjust_trade_size(self, product: str, order_depth: OrderDepth) -> int:
        volatility = self.calculate_volatility(self.price_history[product])
        liquidity = max(sum(abs(v) for v in order_depth.buy_orders.values()), 
                       sum(abs(v) for v in order_depth.sell_orders.values()))
        base_size = self.base_trade_size
        return min(int(base_size * (1 + volatility * self.volatility_factor)), liquidity, self.position_limits[product])

    def run(self, state: TradingState) -> tuple[Dict[str, List[Order]], int, str]:
        result = {}
        conversions = 0
        
        # Load or initialize state
        if state.traderData:
            trader_data = json.loads(state.traderData)
            self.price_history = trader_data["prices"]
            total_orders = trader_data["total_orders"]
            avg_prices = trader_data["avg_prices"]
            current_positions = trader_data["positions"]
        else:
            total_orders = 0
            avg_prices = {p: {"buy": 0, "sell": 0, "count_buy": 0, "count_sell": 0} for p in self.products}
            current_positions = {p: state.position.get(p, 0) for p in self.products}

        # Update price history
        for product in self.products:
            if product in state.order_depths:
                order_depth = state.order_depths[product]
                if order_depth.buy_orders and order_depth.sell_orders:
                    best_bid = max(order_depth.buy_orders.keys())
                    best_ask = min(order_depth.sell_orders.keys())
                    mid_price = (best_bid + best_ask) / 2
                    self.price_history[product].append(mid_price)
                    self.last_mid_prices[product] = mid_price

        # Trading logic
        for product in self.products:
            if product not in state.order_depths or total_orders >= self.max_orders:
                continue
                
            order_depth = state.order_depths[product]
            current_pos = current_positions[product]
            orders = []
            
            best_bid = max(order_depth.buy_orders.keys())
            best_ask = min(order_depth.sell_orders.keys())
            bid_vol = order_depth.buy_orders[best_bid]
            ask_vol = -order_depth.sell_orders[best_ask]
            
            room_to_buy = self.position_limits[product] - current_pos
            room_to_sell = self.position_limits[product] + current_pos
            trade_size = self.adjust_trade_size(product, order_depth)
            remaining_orders = self.max_orders - total_orders

            # RAINFOREST_RESIN: Dynamic mean reversion
            if product == "RAINFOREST_RESIN":
                target_mean = self.calculate_dynamic_mean(self.price_history[product])
                
                if best_ask < target_mean - self.min_profit and room_to_buy >= trade_size:
                    buy_vol = min(trade_size, ask_vol, room_to_buy, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = (avg_prices[product]["buy"] * avg_prices[product]["count_buy"] + best_ask * buy_vol) / (avg_prices[product]["count_buy"] + buy_vol)
                        avg_prices[product]["count_buy"] += buy_vol
                        print(f"BUY {product} {buy_vol}x at {best_ask}")

                if best_bid > target_mean + self.min_profit and room_to_sell >= trade_size:
                    sell_vol = min(trade_size, bid_vol, room_to_sell, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["sell"] = (avg_prices[product]["sell"] * avg_prices[product]["count_sell"] + best_bid * sell_vol) / (avg_prices[product]["count_sell"] + sell_vol)
                        avg_prices[product]["count_sell"] += sell_vol
                        print(f"SELL {product} {sell_vol}x at {best_bid}")

                # Unwind losing positions
                if current_pos > 0 and best_bid < avg_prices[product]["buy"]:
                    sell_vol = min(trade_size, current_pos, bid_vol, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["count_buy"] -= sell_vol
                        print(f"UNWIND SELL {product} {sell_vol}x at {best_bid}")
                
                if current_pos < 0 and best_ask > avg_prices[product]["sell"]:
                    buy_vol = min(trade_size, -current_pos, ask_vol, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["count_sell"] -= buy_vol
                        print(f"UNWIND BUY {product} {buy_vol}x at {best_ask}")

            # KELP: Enhanced trend following with volatility filter
            elif product == "KELP":
                short_ma, long_ma = self.calculate_moving_averages(self.price_history[product])
                volatility = self.calculate_volatility(self.price_history[product])

                if short_ma is not None and long_ma is not None and volatility > 0:
                    if short_ma > long_ma + volatility and room_to_buy >= trade_size:  # Strong bullish signal
                        buy_vol = min(trade_size, ask_vol, room_to_buy, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["buy"] = (avg_prices[product]["buy"] * avg_prices[product]["count_buy"] + best_ask * buy_vol) / (avg_prices[product]["count_buy"] + buy_vol)
                            avg_prices[product]["count_buy"] += buy_vol
                            print(f"TREND BUY {product} {buy_vol}x at {best_ask}")

                    elif short_ma < long_ma - volatility and room_to_sell >= trade_size:  # Strong bearish signal
                        sell_vol = min(trade_size, bid_vol, room_to_sell, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = (avg_prices[product]["sell"] * avg_prices[product]["count_sell"] + best_bid * sell_vol) / (avg_prices[product]["count_sell"] + sell_vol)
                            avg_prices[product]["count_sell"] += sell_vol
                            print(f"TREND SELL {product} {sell_vol}x at {best_bid}")

                    # Unwind positions if price reverses
                    if current_pos > 0 and short_ma < long_ma:
                        sell_vol = min(trade_size, current_pos, bid_vol, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["count_buy"] -= sell_vol
                            print(f"UNWIND SELL {product} {sell_vol}x at {best_bid}")

                    if current_pos < 0 and short_ma > long_ma:
                        buy_vol = min(trade_size, -current_pos, ask_vol, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["count_sell"] -= buy_vol
                            print(f"UNWIND BUY {product} {buy_vol}x at {best_ask}")

            # SQUID_INK: Aggressive pattern-based trading
            elif product == "SQUID_INK":
                pattern = self.detect_squid_pattern(self.price_history[product])
                recent_mean = np.mean(self.price_history[product][-self.squid_pattern_length:]) if self.price_history[product] else 1970

                if pattern == "strong_upward" and room_to_buy >= trade_size:
                    buy_vol = min(trade_size, ask_vol, room_to_buy, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = (avg_prices[product]["buy"] * avg_prices[product]["count_buy"] + best_ask * buy_vol) / (avg_prices[product]["count_buy"] + buy_vol)
                        avg_prices[product]["count_buy"] += buy_vol
                        print(f"STRONG BUY {product} {buy_vol}x at {best_ask}")

                elif pattern == "strong_downward" and room_to_sell >= trade_size:
                    sell_vol = min(trade_size, bid_vol, room_to_sell, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["sell"] = (avg_prices[product]["sell"] * avg_prices[product]["count_sell"] + best_bid * sell_vol) / (avg_prices[product]["count_sell"] + sell_vol)
                        avg_prices[product]["count_sell"] += sell_vol
                        print(f"STRONG SELL {product} {sell_vol}x at {best_bid}")

                elif pattern == "mean_reverting":
                    if best_ask < recent_mean - self.min_profit and room_to_buy >= trade_size:
                        buy_vol = min(trade_size, ask_vol, room_to_buy, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["buy"] = (avg_prices[product]["buy"] * avg_prices[product]["count_buy"] + best_ask * buy_vol) / (avg_prices[product]["count_buy"] + buy_vol)
                            avg_prices[product]["count_buy"] += buy_vol
                            print(f"MEAN BUY {product} {buy_vol}x at {best_ask}")

                    if best_bid > recent_mean + self.min_profit and room_to_sell >= trade_size:
                        sell_vol = min(trade_size, bid_vol, room_to_sell, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = (avg_prices[product]["sell"] * avg_prices[product]["count_sell"] + best_bid * sell_vol) / (avg_prices[product]["count_sell"] + sell_vol)
                            avg_prices[product]["count_sell"] += sell_vol
                            print(f"MEAN SELL {product} {sell_vol}x at {best_bid}")

                # Unwind positions
                if current_pos > 0 and (pattern in ["strong_downward", "no_pattern"] or best_bid < avg_prices[product]["buy"]):
                    sell_vol = min(trade_size, current_pos, bid_vol, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["count_buy"] -= sell_vol
                        print(f"UNWIND SELL {product} {sell_vol}x at {best_bid}")

                if current_pos < 0 and (pattern in ["strong_upward", "no_pattern"] or best_ask > avg_prices[product]["sell"]):
                    buy_vol = min(trade_size, -current_pos, ask_vol, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["count_sell"] -= buy_vol
                        print(f"UNWIND BUY {product} {buy_vol}x at {best_ask}")

            # Arbitrage for all products
            if best_bid > best_ask and room_to_buy >= trade_size:
                arb_vol = min(trade_size * 2, ask_vol, room_to_buy, remaining_orders)  # Double size for arbitrage
                if arb_vol > 0:
                    orders.append(Order(product, best_ask, arb_vol))
                    total_orders += 1
                    avg_prices[product]["buy"] = (avg_prices[product]["buy"] * avg_prices[product]["count_buy"] + best_ask * arb_vol) / (avg_prices[product]["count_buy"] + arb_vol)
                    avg_prices[product]["count_buy"] += arb_vol
                    print(f"ARBITRAGE BUY {product} {arb_vol}x at {best_ask}")

            if orders:
                result[product] = orders

        # Save state
        trader_data = {
            "prices": self.price_history,
            "total_orders": total_orders,
            "avg_prices": avg_prices,
            "positions": current_positions
        }
        trader_data_str = json.dumps(trader_data)

        return result, conversions, trader_data_str