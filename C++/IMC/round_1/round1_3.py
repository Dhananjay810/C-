from datamodel import OrderDepth, TradingState, Order
from typing import Dict, List, Tuple
import json
import numpy as np
from statistics import mean, stdev
from collections import deque

class Trader:
    def __init__(self):
        self.position_limits = {
            "RAINFOREST_RESIN": 50,
            "KELP": 50,
            "SQUID_INK": 50
        }
        self.max_orders = 2000
        self.products = ["RAINFOREST_RESIN", "KELP", "SQUID_INK"]
        self.max_price_history = 1000
        
        # Enhanced product-specific parameters based on dataset analysis
        self.strategy_params = {
            "RAINFOREST_RESIN": {
                "window_long": 50,  # Reduced from 100 for faster response
                "window_short": 10,
                "volatility_window": 30,
                "min_profit_multiplier": 1.8,  # Increased for higher profit targets
                "trade_size_multiplier": 0.25,
                "trend_threshold": 0.25,
                "aggressive_factor": 1.5  # More aggressive in profitable product
            },
            "KELP": {
                "window_long": 30,
                "window_short": 5,
                "volatility_window": 20,
                "min_profit_multiplier": 1.5,  # Increased from 1.2
                "trade_size_multiplier": 0.2,  # Reduced from 0.3 to limit losses
                "trend_threshold": 0.2,
                "reversion_factor": 0.8  # Focus more on mean reversion
            },
            "SQUID_INK": {
                "window_long": 20,
                "window_short": 3,
                "volatility_window": 15,
                "min_profit_multiplier": 2.5,  # Increased from 2.0 for bigger moves
                "trade_size_multiplier": 0.2,
                "trend_threshold": 0.3,
                "pattern_length": 10,
                "breakout_threshold": 1.8  # For volatility breakouts
            }
        }
        
        # Enhanced risk management
        self.max_drawdown = 1000
        self.stop_loss_pct = 0.015  # Tighter stop loss
        self.take_profit_pct = 0.04  # Higher take profit
        self.position_decay = 0.9  # Faster reduction when losing
        self.profit_boost = 1.2  # Increase size when winning

        # Advanced metrics
        self.spread_history = {product: deque(maxlen=100) for product in self.products}
        self.liquidity_thresholds = {
            "RAINFOREST_RESIN": 15,
            "KELP": 10,
            "SQUID_INK": 8
        }

    def calculate_spread(self, order_depth):
        if not order_depth.buy_orders or not order_depth.sell_orders:
            return 0
        best_bid = max(order_depth.buy_orders.keys())
        best_ask = min(order_depth.sell_orders.keys())
        return best_ask - best_bid

    def calculate_moving_averages(self, prices: List[float], product: str) -> Tuple[float, float, float]:
        params = self.strategy_params[product]
        if len(prices) < params["window_long"]:
            return None, None, 0
        
        short_ma = mean(prices[-params["window_short"]:])
        long_ma = mean(prices[-params["window_long"]:])
        
        # Enhanced trend strength calculation
        recent_prices = prices[-params["window_short"]:]
        if len(recent_prices) < 2:
            trend_strength = 0
        else:
            price_changes = np.diff(recent_prices)
            positive_changes = np.sum(price_changes > 0)
            trend_strength = positive_changes / len(price_changes)
            # Add magnitude component
            avg_up_move = np.mean(price_changes[price_changes > 0]) if np.any(price_changes > 0) else 0
            avg_down_move = np.mean(np.abs(price_changes[price_changes < 0])) if np.any(price_changes < 0) else 0
            if avg_down_move > 0:
                trend_strength *= (avg_up_move / avg_down_move)
        
        return short_ma, long_ma, min(max(trend_strength, 0), 1)

    def calculate_volatility(self, prices: List[float], product: str) -> float:
        params = self.strategy_params[product]
        if len(prices) < params["volatility_window"]:
            return 0.0
        recent_prices = prices[-params["volatility_window"]:]
        if len(recent_prices) < 2:
            return 0.0
        return stdev(recent_prices)

    def detect_market_regime(self, prices: List[float], product: str) -> str:
        if len(prices) < 10:
            return "neutral"
        
        params = self.strategy_params[product]
        short_ma, long_ma, trend_strength = self.calculate_moving_averages(prices, product)
        
        if short_ma is None:
            return "neutral"
            
        # Enhanced trend detection with confirmation
        if trend_strength > 0.6 + params["trend_threshold"] and short_ma > long_ma:
            return "uptrend"
        elif trend_strength < 0.4 - params["trend_threshold"] and short_ma < long_ma:
            return "downtrend"
        
        # Enhanced mean-reverting detection with ATR
        atr = self.calculate_atr(prices, product)
        current_range = max(prices[-5:]) - min(prices[-5:])
        
        if current_range > atr * 1.5:
            return "volatile"
            
        return "neutral"

    def calculate_atr(self, prices, product, window=14):
        if len(prices) < window + 1:
            return 0
        true_ranges = []
        for i in range(1, len(prices[-window:])):
            high = max(prices[i], prices[i-1])
            low = min(prices[i], prices[i-1])
            true_ranges.append(high - low)
        return mean(true_ranges) if true_ranges else 0

    def detect_squid_pattern(self, prices: List[float]) -> str:
        params = self.strategy_params["SQUID_INK"]
        if len(prices) < params["pattern_length"]:
            return "no_pattern"
            
        recent = prices[-params["pattern_length"]:]
        changes = np.diff(recent)
        
        # Enhanced pattern detection with smoothing
        smoothed = np.convolve(recent, np.ones(3)/3, mode='valid')
        if len(smoothed) < 2:
            return "no_pattern"
            
        smoothed_changes = np.diff(smoothed)
        positive_changes = np.sum(smoothed_changes > 0)
        trend_strength = positive_changes / len(smoothed_changes)
        
        # Strong trend detection with confirmation
        if trend_strength > 0.85 and all(c >= 0 for c in smoothed_changes[-3:]):
            return "strong_upward"
        elif trend_strength < 0.15 and all(c <= 0 for c in smoothed_changes[-3:]):
            return "strong_downward"
            
        # Enhanced volatility detection
        first_half_vol = stdev(recent[:len(recent)//2]) if len(recent[:len(recent)//2]) > 1 else 0
        second_half_vol = stdev(recent[len(recent)//2:]) if len(recent[len(recent)//2:]) > 1 else 0
        
        if second_half_vol > first_half_vol * params["breakout_threshold"] and first_half_vol > 0:
            return "volatility_expansion"
        elif second_half_vol < first_half_vol * 0.5 and first_half_vol > 0:
            return "volatility_contraction"
            
        return "no_pattern"

    def calculate_dynamic_sizing(self, product: str, volatility: float, current_pnl: float, spread: float) -> Tuple[float, float]:
        params = self.strategy_params[product]
        
        # Spread-adjusted base size
        spread_factor = max(0.5, 1 - (spread / (volatility + 1e-6)))
        base_size = max(1, int(volatility * params["trade_size_multiplier"] * 100 * spread_factor))
        
        # Enhanced performance adjustment
        if current_pnl > 0:
            # Increase size when profitable
            performance_factor = self.profit_boost ** (current_pnl / (self.max_drawdown * 0.1))
        else:
            # Decrease size when losing
            performance_factor = self.position_decay ** (abs(current_pnl) / (self.max_drawdown * 0.1))
            
        # Product-specific adjustments
        if product == "RAINFOREST_RESIN":
            performance_factor *= params["aggressive_factor"]
        elif product == "KELP":
            performance_factor *= params["reversion_factor"]
            
        # Final trade size with liquidity consideration
        trade_size = max(1, int(base_size * performance_factor))
        
        # Dynamic profit target based on volatility and spread
        min_profit = max(1, volatility * params["min_profit_multiplier"] + spread * 0.5)
        
        return trade_size, min_profit

    def run(self, state: TradingState) -> Tuple[Dict[str, List[Order]], int, str]:
        result = {}
        conversions = 0

        # Initialize or load trader data
        if state.traderData:
            try:
                trader_data = json.loads(state.traderData)
                prices = {k: deque(v, maxlen=self.max_price_history) for k, v in trader_data.get("prices", {}).items()}
                total_orders = trader_data.get("total_orders", 0)
                avg_prices = trader_data.get("avg_prices", {p: {"buy": 0, "sell": 0} for p in self.products})
                volatilities = trader_data.get("volatilities", {p: 0 for p in self.products})
                last_pnl = trader_data.get("last_pnl", 0.0)
                positions = trader_data.get("positions", {p: 0 for p in self.products})
            except json.JSONDecodeError:
                prices = {p: deque(maxlen=self.max_price_history) for p in self.products}
                total_orders = 0
                avg_prices = {p: {"buy": 0, "sell": 0} for p in self.products}
                volatilities = {p: 0 for p in self.products}
                last_pnl = 0.0
                positions = {p: 0 for p in self.products}
        else:
            prices = {p: deque(maxlen=self.max_price_history) for p in self.products}
            total_orders = 0
            avg_prices = {p: {"buy": 0, "sell": 0} for p in self.products}
            volatilities = {p: 0 for p in self.products}
            last_pnl = 0.0
            positions = {p: 0 for p in self.products}

        current_positions = {p: state.position.get(p, 0) for p in self.products}
        current_pnl = last_pnl

        # Update price history and calculate metrics
        for product in self.products:
            if product in state.order_depths:
                order_depth = state.order_depths[product]
                if order_depth.buy_orders and order_depth.sell_orders:
                    best_bid = max(order_depth.buy_orders.keys())
                    best_ask = min(order_depth.sell_orders.keys())
                    mid_price = (best_bid + best_ask) / 2
                    prices[product].append(mid_price)
                    volatilities[product] = self.calculate_volatility(list(prices[product]), product)
                    self.spread_history[product].append(self.calculate_spread(order_depth))

        # Trading logic per product
        for product in self.products:
            if product not in state.order_depths or total_orders >= self.max_orders:
                continue

            order_depth = state.order_depths[product]
            current_pos = current_positions[product]
            orders = []

            best_bid = max(order_depth.buy_orders.keys()) if order_depth.buy_orders else 0
            best_ask = min(order_depth.sell_orders.keys()) if order_depth.sell_orders else float('inf')
            bid_vol = order_depth.buy_orders.get(best_bid, 0) if order_depth.buy_orders else 0
            ask_vol = order_depth.sell_orders.get(best_ask, 0) if order_depth.sell_orders else 0

            if best_ask == float('inf') or best_bid == 0:
                continue

            # Calculate dynamic parameters with spread adjustment
            avg_spread = mean(self.spread_history[product]) if self.spread_history[product] else 0
            trade_size, min_profit = self.calculate_dynamic_sizing(
                product, volatilities[product], current_pnl, avg_spread
            )
            
            room_to_buy = self.position_limits[product] - current_pos
            room_to_sell = self.position_limits[product] + current_pos
            remaining_orders = self.max_orders - total_orders

            # Enhanced trading strategies per product
            if product == "RAINFOREST_RESIN":
                market_regime = self.detect_market_regime(list(prices[product]), product)
                short_ma, long_ma, trend_strength = self.calculate_moving_averages(list(prices[product]), product)
                
                # More aggressive in profitable product
                trade_size = int(trade_size * 1.5)
                
                if market_regime == "uptrend" and current_pos < self.position_limits[product]:
                    # Buy with more confidence in uptrend
                    if short_ma is not None and best_ask < short_ma + min_profit * 0.5:
                        buy_vol = min(trade_size, ask_vol, room_to_buy, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["buy"] = (
                                avg_prices[product]["buy"] * current_pos + best_ask * buy_vol
                            ) / (current_pos + buy_vol) if (current_pos + buy_vol) != 0 else best_ask
                
                elif market_regime == "downtrend" and current_pos > -self.position_limits[product]:
                    # Short with more confidence in downtrend
                    if short_ma is not None and best_bid > short_ma - min_profit * 0.5:
                        sell_vol = min(trade_size, bid_vol, room_to_sell, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = (
                                avg_prices[product]["sell"] * abs(current_pos) + best_bid * sell_vol
                            ) / (abs(current_pos) + sell_vol) if (abs(current_pos) + sell_vol) != 0 else best_bid
                
                # Mean-reversion with tighter spreads
                if avg_spread < volatilities[product] * 0.3:
                    if long_ma is not None:
                        if best_ask < long_ma - min_profit * 1.2 and room_to_buy >= trade_size:
                            buy_vol = min(trade_size, ask_vol, room_to_buy, remaining_orders)
                            if buy_vol > 0:
                                orders.append(Order(product, best_ask, buy_vol))
                                total_orders += 1
                                avg_prices[product]["buy"] = best_ask
                        
                        if best_bid > long_ma + min_profit * 1.2 and room_to_sell >= trade_size:
                            sell_vol = min(trade_size, bid_vol, room_to_sell, remaining_orders)
                            if sell_vol > 0:
                                orders.append(Order(product, best_bid, -sell_vol))
                                total_orders += 1
                                avg_prices[product]["sell"] = best_bid
                
                # Take profit and stop loss with dynamic levels
                if current_pos > 0 and avg_prices[product]["buy"] > 0:
                    take_profit_level = avg_prices[product]["buy"] * (1 + self.take_profit_pct * (1 + trend_strength))
                    stop_loss_level = avg_prices[product]["buy"] * (1 - self.stop_loss_pct * (1 - trend_strength))
                    
                    if best_bid >= take_profit_level:
                        sell_vol = min(current_pos, bid_vol, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                    elif best_bid <= stop_loss_level:
                        sell_vol = min(current_pos, bid_vol, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                
                if current_pos < 0 and avg_prices[product]["sell"] > 0:
                    take_profit_level = avg_prices[product]["sell"] * (1 - self.take_profit_pct * (1 + trend_strength))
                    stop_loss_level = avg_prices[product]["sell"] * (1 + self.stop_loss_pct * (1 - trend_strength))
                    
                    if best_ask <= take_profit_level:
                        buy_vol = min(-current_pos, ask_vol, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                    elif best_ask >= stop_loss_level:
                        buy_vol = min(-current_pos, ask_vol, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1

            elif product == "KELP":
                market_regime = self.detect_market_regime(list(prices[product]), product)
                short_ma, long_ma, trend_strength = self.calculate_moving_averages(list(prices[product]), product)
                
                # More conservative approach for KELP
                trade_size = int(trade_size * 0.8)
                
                # Focus on mean-reversion for KELP
                if market_regime == "volatile":
                    if long_ma is not None:
                        if best_ask < long_ma - min_profit * 1.5 and room_to_buy >= trade_size:
                            buy_vol = min(trade_size, ask_vol, room_to_buy, remaining_orders)
                            if buy_vol > 0:
                                orders.append(Order(product, best_ask, buy_vol))
                                total_orders += 1
                                avg_prices[product]["buy"] = best_ask
                        
                        if best_bid > long_ma + min_profit * 1.5 and room_to_sell >= trade_size:
                            sell_vol = min(trade_size, bid_vol, room_to_sell, remaining_orders)
                            if sell_vol > 0:
                                orders.append(Order(product, best_bid, -sell_vol))
                                total_orders += 1
                                avg_prices[product]["sell"] = best_bid
                
                # Tight stop losses for KELP
                if current_pos > 0 and avg_prices[product]["buy"] > 0:
                    if best_bid >= avg_prices[product]["buy"] * (1 + self.take_profit_pct * 0.8):
                        sell_vol = min(current_pos, bid_vol, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                    elif best_bid <= avg_prices[product]["buy"] * (1 - self.stop_loss_pct * 0.8):
                        sell_vol = min(current_pos, bid_vol, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                
                if current_pos < 0 and avg_prices[product]["sell"] > 0:
                    if best_ask <= avg_prices[product]["sell"] * (1 - self.take_profit_pct * 0.8):
                        buy_vol = min(-current_pos, ask_vol, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                    elif best_ask >= avg_prices[product]["sell"] * (1 + self.stop_loss_pct * 0.8):
                        buy_vol = min(-current_pos, ask_vol, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1

            elif product == "SQUID_INK":
                pattern = self.detect_squid_pattern(list(prices[product]))
                short_ma, long_ma, trend_strength = self.calculate_moving_averages(list(prices[product]), product)
                
                # More aggressive breakout trading for SQUID_INK
                if pattern == "strong_upward" and room_to_buy >= trade_size:
                    buy_vol = min(trade_size * 2, ask_vol, room_to_buy, remaining_orders)
                    if buy_vol > 0:
                        orders.append(Order(product, best_ask, buy_vol))
                        total_orders += 1
                        avg_prices[product]["buy"] = best_ask
                
                elif pattern == "strong_downward" and room_to_sell >= trade_size:
                    sell_vol = min(trade_size * 2, bid_vol, room_to_sell, remaining_orders)
                    if sell_vol > 0:
                        orders.append(Order(product, best_bid, -sell_vol))
                        total_orders += 1
                        avg_prices[product]["sell"] = best_bid
                
                elif pattern == "volatility_expansion":
                    # Trade breakouts in direction of initial move
                    initial_move = prices[product][-1] - prices[product][-2]
                    if initial_move > 0 and room_to_buy >= trade_size:
                        buy_vol = min(trade_size, ask_vol, room_to_buy, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["buy"] = best_ask
                    elif initial_move < 0 and room_to_sell >= trade_size:
                        sell_vol = min(trade_size, bid_vol, room_to_sell, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["sell"] = best_bid
                
                # Tight stops for SQUID_INK to capture quick moves
                if current_pos > 0 and avg_prices[product]["buy"] > 0:
                    if best_bid >= avg_prices[product]["buy"] * (1 + self.take_profit_pct * 1.5):
                        sell_vol = min(current_pos, bid_vol, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                    elif best_bid <= avg_prices[product]["buy"] * (1 - self.stop_loss_pct * 0.5):
                        sell_vol = min(current_pos, bid_vol, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                
                if current_pos < 0 and avg_prices[product]["sell"] > 0:
                    if best_ask <= avg_prices[product]["sell"] * (1 - self.take_profit_pct * 1.5):
                        buy_vol = min(-current_pos, ask_vol, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                    elif best_ask >= avg_prices[product]["sell"] * (1 + self.stop_loss_pct * 0.5):
                        buy_vol = min(-current_pos, ask_vol, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1

            if orders:
                result[product] = orders

        # Save state with deque converted to list
        trader_data = {
            "prices": {k: list(v) for k, v in prices.items()},
            "total_orders": total_orders,
            "avg_prices": avg_prices,
            "volatilities": volatilities,
            "last_pnl": current_pnl,
            "positions": current_positions
        }
        trader_data_str = json.dumps(trader_data)

        return result, conversions, trader_data_str