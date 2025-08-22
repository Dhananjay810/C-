import numpy as np
from datamodel import Order, TradingState
from typing import Dict, List, Tuple
from collections import deque
import json

class Trader:
    def _init_(self):
        # Initialize position limits
        self.position_limits = {
            "RAINFOREST_RESIN": 50,
            "KELP": 50
        }
        
        # Market data structures
        self.kelp_prices = deque(maxlen=100)
        self.resin_spread_history = deque(maxlen=20)
        
        # Technical indicators storage
        self.kelp_indicators = {
            'sma': None,      # Simple Moving Average
            'ema': None,      # Exponential Moving Average
            'rsi': None,      # Relative Strength Index
            'macd': None,     # Moving Average Convergence Divergence
            'atr': None       # Average True Range
        }
        
        # Risk management parameters
        self.portfolio_value = 100000  # Initial estimate
        self.max_loss_per_trade = 0.02  # 2% of portfolio
        self.stop_loss_pct = 0.05      # 5% stop loss
        self.take_profit_pct = 0.08    # 8% take profit
        
        # Trading parameters
        self.optimal_params = {
            "resin_spread": 0.8,
            "kelp_window": 10,
            "max_trade_size": 10,
            "volatility_adjustment": True
        }

    def run(self, state: TradingState) -> Tuple[Dict[str, List[Order]], int, str]:
        """Main trading function called each tick"""
        result = {}
        self._update_portfolio_value(state)
        
        # Precompute market data for all products
        market_data = {
            product: self._get_market_data(state, product)
            for product in state.order_depths
        }
        
        # Update technical indicators for Kelp
        if "KELP" in market_data:
            self._update_technical_indicators(market_data["KELP"])
        
        # Execute trading strategies with risk management
        for product, data in market_data.items():
            position = state.position.get(product, 0)
            
            if product == "RAINFOREST_RESIN":
                orders = self._resin_strategy(data, position)
            elif product == "KELP":
                orders = self._kelp_strategy(data, position)
            
            # Apply risk management filters
            result[product] = self._apply_risk_management(product, orders, position)
        
        return result, 0, self._serialize_state()

    def _get_market_data(self, state, product) -> dict:
        """Extract and structure market data efficiently"""
        order_depth = state.order_depths[product]
        bids = sorted(order_depth.buy_orders.items(), reverse=True)
        asks = sorted(order_depth.sell_orders.items())
        
        return {
            'best_bid': bids[0][0] if bids else None,
            'best_ask': asks[0][0] if asks else None,
            'bid_volume': sum(v for _, v in bids[:3]),  # Top 3 bid levels
            'ask_volume': sum(abs(v) for _, v in asks[:3]),  # Top 3 ask levels
            'mid_price': (bids[0][0] + asks[0][0])/2 if bids and asks else None,
            'spread': asks[0][0] - bids[0][0] if bids and asks else None
        }

    def _update_technical_indicators(self, kelp_data):
        """Calculate and update all technical indicators for Kelp"""
        if kelp_data['mid_price']:
            self.kelp_prices.append(kelp_data['mid_price'])
            
            if len(self.kelp_prices) >= self.optimal_params["kelp_window"]:
                prices = np.array(self.kelp_prices)
                window = self.optimal_params["kelp_window"]
                
                # Simple Moving Average
                self.kelp_indicators['sma'] = np.mean(prices[-window:])
                
                # Exponential Moving Average
                weights = np.exp(np.linspace(0, 1, window))
                self.kelp_indicators['ema'] = np.average(prices[-window:], weights=weights)
                
                # Relative Strength Index (14-period)
                deltas = np.diff(prices[-14:])
                gains = deltas[deltas > 0].sum() or 0.1
                losses = -deltas[deltas < 0].sum() or 0.1
                self.kelp_indicators['rsi'] = 100 - (100 / (1 + gains/losses))
                
                # MACD (12/26 EMA difference)
                if len(self.kelp_prices) >= 26:
                    ema12 = np.average(prices[-12:], weights=np.exp(np.linspace(0, 1, 12)))
                    ema26 = np.average(prices[-26:], weights=np.exp(np.linspace(0, 1, 26)))
                    self.kelp_indicators['macd'] = ema12 - ema26
                
                # Average True Range
                if len(self.kelp_prices) >= 14 and kelp_data['best_bid'] and kelp_data['best_ask']:
                    high_low = kelp_data['best_ask'] - kelp_data['best_bid']
                    high_close = abs(kelp_data['best_ask'] - prices[-2])
                    low_close = abs(kelp_data['best_bid'] - prices[-2])
                    self.kelp_indicators['atr'] = max(high_low, high_close, low_close)

    def _resin_strategy(self, data: dict, position: int) -> List[Order]:
        """Market making strategy for Rainforest Resin"""
        orders = []
        if data['mid_price'] is None:
            return orders
        
        # Dynamic spread adjustment based on recent spreads
        if data['spread']:
            self.resin_spread_history.append(data['spread'])
            avg_spread = np.mean(self.resin_spread_history) if self.resin_spread_history else 2.0
            spread = min(max(0.5, avg_spread * 0.6), 2.0)
        else:
            spread = self.optimal_params["resin_spread"]
        
        # Calculate order prices
        bid_price = round(data['mid_price'] - spread, 2)
        ask_price = round(data['mid_price'] + spread, 2)
        
        # Inventory-aware position sizing
        position_pct = position / self.position_limits["RAINFOREST_RESIN"]
        max_buy = min(
            self.optimal_params["max_trade_size"],
            int((1 - position_pct) * self.optimal_params["max_trade_size"] * 2)
        )
        max_sell = min(
            self.optimal_params["max_trade_size"],
            int((1 + position_pct) * self.optimal_params["max_trade_size"] * 2)
        )
        
        # Create orders
        if max_buy > 0:
            orders.append(Order("RAINFOREST_RESIN", bid_price, max_buy))
        if max_sell > 0:
            orders.append(Order("RAINFOREST_RESIN", ask_price, -max_sell))
            
        return orders

    def _kelp_strategy(self, data: dict, position: int) -> List[Order]:
        """Trend-following strategy for Kelp with multiple indicators"""
        orders = []
        if data['mid_price'] is None or len(self.kelp_prices) < self.optimal_params["kelp_window"]:
            return orders
        
        # Calculate weighted trend score
        trend_score = 0
        weights = {'sma': 0.3, 'ema': 0.3, 'rsi': 0.2, 'macd': 0.2}
        
        for indicator, weight in weights.items():
            if self.kelp_indicators[indicator] is not None:
                if indicator == 'rsi':
                    # Normalize RSI to [-1, 1] range
                    trend_score += weight * ((self.kelp_indicators['rsi'] - 50) / 50)
                elif indicator == 'macd':
                    # Normalize MACD by ATR
                    norm_macd = self.kelp_indicators['macd'] / (self.kelp_indicators['atr'] or 1)
                    trend_score += weight * np.tanh(norm_macd * 2)
                else:
                    # Price relation to moving averages
                    price_relation = (data['mid_price'] - self.kelp_indicators[indicator]) / data['mid_price']
                    trend_score += weight * np.tanh(price_relation * 100)
        
        # Volatility-adjusted position sizing
        atr_multiplier = 1 / (self.kelp_indicators['atr'] or 1)
        position_size = min(
            self.optimal_params["max_trade_size"],
            int(abs(trend_score) * self.optimal_params["max_trade_size"] * atr_multiplier)
        )
        
        # Generate orders based on trend strength
        if trend_score > 0.2:  # Strong uptrend
            size = min(position_size, self.position_limits["KELP"] - position)
            if size > 0:
                orders.append(Order("KELP", data['best_ask'], size))
        elif trend_score < -0.2:  # Strong downtrend
            size = min(position_size, self.position_limits["KELP"] + position)
            if size > 0:
                orders.append(Order("KELP", data['best_bid'], -size))
                
        return orders

    def _apply_risk_management(self, product: str, orders: List[Order], position: int) -> List[Order]:
        """Apply risk management filters to orders"""
        filtered_orders = []
        
        for order in orders:
            # Position limit check
            projected_position = position + order.quantity
            if abs(projected_position) > self.position_limits[product]:
                continue
            
            # Maximum loss per trade check
            trade_value = abs(order.price * order.quantity)
            if trade_value > self.portfolio_value * self.max_loss_per_trade:
                adjusted_qty = int((self.portfolio_value * self.max_loss_per_trade) / order.price)
                if adjusted_qty > 0:
                    order.quantity = adjusted_qty if order.quantity > 0 else -adjusted_qty
            
            # Stop loss/take profit logic for Kelp
            if product == "KELP" and len(self.kelp_prices) > 1:
                last_price = self.kelp_prices[-1]
                if order.quantity > 0:  # Buy order
                    stop_price = order.price * (1 - self.stop_loss_pct)
                    take_profit = order.price * (1 + self.take_profit_pct)
                    if last_price < stop_price or last_price > take_profit:
                        continue
                else:  # Sell order
                    stop_price = order.price * (1 + self.stop_loss_pct)
                    take_profit = order.price * (1 - self.take_profit_pct)
                    if last_price > stop_price or last_price < take_profit:
                        continue
            
            filtered_orders.append(order)
        
        return filtered_orders

    def _update_portfolio_value(self, state: TradingState):
        """Estimate current portfolio value based on positions"""
        self.portfolio_value = 100000  # Base value
        for product, position in state.position.items():
            if product in state.order_depths:
                bids = state.order_depths[product].buy_orders
                asks = state.order_depths[product].sell_orders
                if bids and asks:
                    mid_price = (max(bids.keys()) + min(asks.keys())) / 2
                    self.portfolio_value += position * mid_price

    def _serialize_state(self) -> str:
        """Serialize important state for next iteration"""
        return json.dumps({
            'kelp_prices': list(self.kelp_prices),
            'resin_spreads': list(self.resin_spread_history),
            'indicators': {k: v for k, v in self.kelp_indicators.items() if v is not None}
        })