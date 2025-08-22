from datamodel import OrderDepth, TradingState, Order
from typing import Dict, List
import json
import numpy as np

class Trader:
    def _init_(self):
        self.position_limits = {
            "RAINFOREST_RESIN": 50,
            "KELP": 50,
            "SQUID_INK": 50
        }
        self.max_orders = 2000
        self.window_short = 10  # Increased for more stability
        self.window_long = 50   # Increased for more robust trends
        self.resin_window = 100  # Window for dynamic mean of Rainforest Resin
        self.min_profit_base = 2  # Base minimum profit
        self.trade_size_base = 5  # Base trade size
        self.products = ["RAINFOREST_RESIN", "KELP", "SQUID_INK"]
        self.squid_pattern_length = 15  # Increased for better pattern detection
        self.max_drawdown = 1000  # Maximum acceptable loss before pausing trading
    
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
            return 10000.0  # Default mean if insufficient data
        return np.mean(prices[-window:])
    
    def detect_squid_pattern(self, prices: List[float]) -> str:
        """Enhanced pattern detection for Squid Ink"""
        if len(prices) < self.squid_pattern_length:
            return "no_pattern"
            
        recent = prices[-self.squid_pattern_length:]
        changes = [recent[i] - recent[i-1] for i in range(1, len(recent))]
        vols = [len(state.order_depths["SQUID_INK"].buy_orders) + len(state.order_depths["SQUID_INK"].sell_orders) for state in prices]  # Simplified volume proxy
        
        # Check for strong upward trend (price and volume increase)
        if all(c >= 0 for c in changes) and np.mean(vols[-self.squid_pattern_length:]) > np.mean(vols):
            return "strong_upward"
        # Check for strong downward trend
        elif all(c <= 0 for c in changes) and np.mean(vols[-self.squid_pattern_length:]) > np.mean(vols):
            return "strong_downward"
        # Check for mean reversion (alternating with increasing volume)
        elif all(changes[i] * changes[i+1] < 0 for i in range(len(changes)-1)) and np.var(vols[-self.squid_pattern_length:]) > 0:
            return "mean_reverting"
        else:
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
        
        # Ensure all products have a position, default to 0 if missing
        current_positions = {p: state.position.get(p, 0) for p in self.products}
        
        # Update price history and calculate metrics
        for product in self.products:
            if product in state.order_depths:
                order_depth = state.order_depths[product]
                if order_depth.buy_orders and order_depth.sell_orders:
                    best_bid = max(order_depth.buy_orders.keys())
                    best_ask = min(order_depth.sell_orders.keys())
                    mid_price = (best_bid + best_ask) / 2
                    prices[product].append(mid_price)
                    volatilities[product] = self.calculate_volatility(prices[product], 20)  # 20-period volatility
        
        # Check drawdown
        current_pnl = state.position_value - last_pnl if hasattr(state, 'position_value') else 0.0
        if abs(current_pnl - last_pnl) > self.max_drawdown:
            print("Max drawdown exceeded, pausing trading.")
            return {}, conversions, json.dumps({
                "prices": prices,
                "total_orders": total_orders,
                "avg_prices": avg_prices,
                "volatilities": volatilities,
                "last_pnl": last_pnl
            })
        
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
            
            dynamic_min_profit = max(self.min_profit_base, volatilities[product] * 0.5)  # Volatility-adjusted profit
            dynamic_trade_size = max(1, min(self.trade_size_base, int(volatilities[product] * 10)))  # Volatility-adjusted size
            
            # KELP: Trend following with volatility adjustment
            if product == "KELP":
                short_ma, long_ma = self.calculate_moving_averages(prices[product])
                if short_ma is not None and long_ma is not None and volatilities[product] > 0.1:  # Only trade if volatile
                    if short_ma < long_ma and room_to_sell >= dynamic_trade_size:
                        sell_vol = min(dynamic_trade_size, bid_vol, room_to_sell, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = (avg_prices[product]["sell"] * abs(current_pos) + best_bid * sell_vol) / (abs(current_pos) + sell_vol) if current_pos - sell_vol < 0 else best_bid
                            print(f"SELL {product} {sell_vol}x at {best_bid}")
                    
                    if current_pos < 0 and best_ask <= avg_prices[product]["sell"] - dynamic_min_profit:
                        buy_vol = min(dynamic_trade_size, -current_pos, ask_vol, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = 0 if current_pos + buy_vol == 0 else avg_prices[product]["sell"]
                            print(f"UNWIND BUY {product} {buy_vol}x at {best_ask}")
            
            # RAINFOREST_RESIN: Mean reversion with dynamic mean
            elif product == "RAINFOREST_RESIN":
                dynamic_mean = self.calculate_dynamic_mean(prices[product], self.resin_window)
                
                if best_ask <= dynamic_mean - dynamic_min_profit and room_to_buy >= dynamic_trade_size:
                    buy_vol = min(dynamic_trade_size, ask_vol, room_to_buy, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = (avg_prices[product]["buy"] * current_pos + best_ask * buy_vol) / (current_pos + buy_vol) if current_pos + buy_vol != 0 else best_ask
                        print(f"BUY {product} {buy_vol}x at {best_ask}")
                
                if best_bid >= dynamic_mean + dynamic_min_profit and room_to_sell >= dynamic_trade_size:
                    sell_vol = min(dynamic_trade_size, bid_vol, room_to_sell, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = 0 if current_pos - sell_vol == 0 else avg_prices[product]["buy"]
                        print(f"SELL {product} {sell_vol}x at {best_bid}")
                
                if current_pos > 0 and best_bid >= avg_prices[product]["buy"] + dynamic_min_profit:
                    sell_vol = min(dynamic_trade_size, current_pos, bid_vol, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = 0 if current_pos - sell_vol == 0 else avg_prices[product]["buy"]
                        print(f"UNWIND SELL {product} {sell_vol}x at {best_bid}")
            
            # SQUID_INK: Enhanced pattern detection
            elif product == "SQUID_INK":
                pattern = self.detect_squid_pattern(prices[product])
                
                if pattern == "strong_upward" and room_to_buy >= dynamic_trade_size:
                    buy_vol = min(dynamic_trade_size, ask_vol, room_to_buy, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = (avg_prices[product]["buy"] * current_pos + best_ask * buy_vol) / (current_pos + buy_vol) if current_pos + buy_vol != 0 else best_ask
                        print(f"TREND BUY {product} {buy_vol}x at {best_ask}")
                
                elif pattern == "strong_downward" and room_to_sell >= dynamic_trade_size:
                    sell_vol = min(dynamic_trade_size, bid_vol, room_to_sell, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["sell"] = (avg_prices[product]["sell"] * abs(current_pos) + best_bid * sell_vol) / (abs(current_pos) + sell_vol) if current_pos - sell_vol < 0 else best_bid
                        print(f"TREND SELL {product} {sell_vol}x at {best_bid}")
                
                elif pattern == "mean_reverting":
                    mid_price = np.mean(prices[product][-self.squid_pattern_length:])
                    
                    if best_ask <= mid_price - dynamic_min_profit and room_to_buy >= dynamic_trade_size:
                        buy_vol = min(dynamic_trade_size, ask_vol, room_to_buy, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["buy"] = (avg_prices[product]["buy"] * current_pos + best_ask * buy_vol) / (current_pos + buy_vol) if current_pos + buy_vol != 0 else best_ask
                            print(f"MEAN BUY {product} {buy_vol}x at {best_ask}")
                    
                    if best_bid >= mid_price + dynamic_min_profit and room_to_sell >= dynamic_trade_size:
                        sell_vol = min(dynamic_trade_size, bid_vol, room_to_sell, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = (avg_prices[product]["sell"] * abs(current_pos) + best_bid * sell_vol) / (abs(current_pos) + sell_vol) if current_pos - sell_vol < 0 else best_bid
                            print(f"MEAN SELL {product} {sell_vol}x at {best_bid}")
                
                # Unwind positions
                if current_pos > 0 and best_bid >= avg_prices[product]["buy"] + dynamic_min_profit:
                    sell_vol = min(dynamic_trade_size, current_pos, bid_vol, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = 0 if current_pos - sell_vol == 0 else avg_prices[product]["buy"]
                        print(f"UNWIND SELL {product} {sell_vol}x at {best_bid}")
                
                if current_pos < 0 and best_ask <= avg_prices[product]["sell"] - dynamic_min_profit:
                    buy_vol = min(dynamic_trade_size, -current_pos, ask_vol, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["sell"] = 0 if current_pos + buy_vol == 0 else avg_prices[product]["sell"]
                        print(f"UNWIND BUY {product} {buy_vol}x at {best_ask}")
            
            # Arbitrage (only if spread is significant and volatile)
            spread = best_ask - best_bid
            if spread < 0 and spread < -dynamic_min_profit and room_to_buy >= dynamic_trade_size and volatilities[product] > 0.1:
                arb_vol = min(dynamic_trade_size, ask_vol, room_to_buy, remaining_orders)
                if arb_vol > 0:
                    orders.append(Order(product, best_ask, arb_vol))
                    total_orders += 1
                    avg_prices[product]["buy"] = (avg_prices[product]["buy"] * current_pos + best_ask * arb_vol) / (current_pos + arb_vol) if current_pos + arb_vol != 0 else best_ask
                    print(f"ARBITRAGE BUY {product} {arb_vol}x at {best_ask}")
            
            if orders:
                result[product] = orders
        
        # Save state
        trader_data = {
            "prices": prices,
            "total_orders": total_orders,
            "avg_prices": avg_prices,
            "volatilities": volatilities,
            "last_pnl": current_pnl if hasattr(state, 'position_value') else last_pnl
        }
        trader_data_str = json.dumps(trader_data)
        
        return result, conversions, trader_data_str