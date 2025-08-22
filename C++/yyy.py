import numpy as np
from datamodel import Order, TradingState
from typing import Dict, List, Tuple
from collections import deque
import json

class Trader:
    def _init_(self):
        # Position Limits
        self.position_limits = {"RAINFOREST_RESIN": 50, "KELP": 50}
        
        # Market data storage
        self.kelp_prices = deque(maxlen=100)
        self.resin_spread_history = deque(maxlen=20)
        
        # Technical indicators storage
        self.kelp_indicators = {'sma': 0, 'ema': 0, 'rsi': 0, 'macd': 0, 'atr': 0}
        
        # Risk Management
        self.portfolio_value = 100000  
        self.max_loss_per_trade = 0.02  
        self.stop_loss_pct = 0.05  
        self.take_profit_pct = 0.08  

        # Trading Parameters
        self.optimal_params = {
            "resin_spread": 0.8, "kelp_window": 10, "max_trade_size": 10, "volatility_adjustment": True
        }

    def run(self, state: TradingState) -> Tuple[Dict[str, List[Order]], int, str]:
        result = {}
        self._update_portfolio_value(state)

        market_data = {
            product: self._get_market_data(state, product)
            for product in state.order_depths
        }

        if "KELP" in market_data:
            self._update_technical_indicators(market_data["KELP"])

        for product, data in market_data.items():
            position = state.position.get(product, 0)

            if product == "RAINFOREST_RESIN":
                orders = self._resin_strategy(data, position)
            elif product == "KELP":
                orders = self._kelp_strategy(data, position)

            result[product] = self._apply_risk_management(product, orders, position)

        return result, 0, self._serialize_state()

    def _get_market_data(self, state, product) -> dict:
        """Efficiently extract market data"""
        order_depth = state.order_depths[product]
        bids = sorted(order_depth.buy_orders.items(), reverse=True)
        asks = sorted(order_depth.sell_orders.items())

        best_bid = bids[0][0] if bids else None
        best_ask = asks[0][0] if asks else None
        mid_price = (best_bid + best_ask) / 2 if best_bid and best_ask else None
        spread = best_ask - best_bid if best_bid and best_ask else None

        return {
            'best_bid': best_bid, 'best_ask': best_ask,
            'bid_volume': sum(v for _, v in bids[:3]),
            'ask_volume': sum(abs(v) for _, v in asks[:3]),
            'mid_price': mid_price, 'spread': spread
        }

    def _update_technical_indicators(self, kelp_data):
        """Rolling update for technical indicators"""
        mid_price = kelp_data['mid_price']
        if not mid_price:
            return

        self.kelp_prices.append(mid_price)
        prices = np.array(self.kelp_prices)
        window = self.optimal_params["kelp_window"]

        if len(self.kelp_prices) >= window:
            self.kelp_indicators['sma'] = np.mean(prices[-window:])
            alpha = 2 / (window + 1)
            self.kelp_indicators['ema'] = alpha * prices[-1] + (1 - alpha) * self.kelp_indicators['ema']

        if len(prices) >= 14:
            deltas = np.diff(prices[-14:])
            gains = np.sum(deltas[deltas > 0]) or 0.1
            losses = -np.sum(deltas[deltas < 0]) or 0.1
            self.kelp_indicators['rsi'] = 100 - (100 / (1 + gains / losses))

        if len(prices) >= 26:
            ema12 = np.mean(prices[-12:])
            ema26 = np.mean(prices[-26:])
            self.kelp_indicators['macd'] = ema12 - ema26

        if len(prices) >= 14 and kelp_data['best_bid'] and kelp_data['best_ask']:
            high_low = kelp_data['best_ask'] - kelp_data['best_bid']
            self.kelp_indicators['atr'] = np.mean([high_low, abs(prices[-2] - kelp_data['best_ask']), abs(prices[-2] - kelp_data['best_bid'])])

    def _resin_strategy(self, data: dict, position: int) -> List[Order]:
        """Market making strategy for Rainforest Resin"""
        orders = []
        if not data['mid_price']:
            return orders

        spread = np.mean(self.resin_spread_history) * 0.6 if self.resin_spread_history else self.optimal_params["resin_spread"]
        spread = min(max(0.5, spread), 2.0)

        bid_price = round(data['mid_price'] - spread, 2)
        ask_price = round(data['mid_price'] + spread, 2)

        max_trade = self.optimal_params["max_trade_size"]
        max_buy = min(max_trade, self.position_limits["RAINFOREST_RESIN"] - position)
        max_sell = min(max_trade, self.position_limits["RAINFOREST_RESIN"] + position)

        if max_buy > 0:
            orders.append(Order("RAINFOREST_RESIN", bid_price, max_buy))
        if max_sell > 0:
            orders.append(Order("RAINFOREST_RESIN", ask_price, -max_sell))

        return orders

    def _kelp_strategy(self, data: dict, position: int) -> List[Order]:
        """Trend-following strategy for Kelp"""
        orders = []
        if not data['mid_price'] or len(self.kelp_prices) < self.optimal_params["kelp_window"]:
            return orders

        trend_score = sum(
            weight * ((self.kelp_indicators[indicator] - 50) / 50 if indicator == 'rsi'
                      else np.tanh((data['mid_price'] - self.kelp_indicators[indicator]) * 100))
            for indicator, weight in {'sma': 0.3, 'ema': 0.3, 'rsi': 0.2, 'macd': 0.2}.items()
            if self.kelp_indicators[indicator] is not None
        )

        atr_multiplier = 1 / (self.kelp_indicators['atr'] or 1)
        position_size = min(self.optimal_params["max_trade_size"], int(abs(trend_score) * atr_multiplier))

        if trend_score > 0.2 and position_size > 0:
            orders.append(Order("KELP", data['best_ask'], min(position_size, self.position_limits["KELP"] - position)))
        elif trend_score < -0.2 and position_size > 0:
            orders.append(Order("KELP", data['best_bid'], -min(position_size, self.position_limits["KELP"] + position)))

        return orders

    def _update_portfolio_value(self, state: TradingState):
        """Efficient portfolio value update"""
        self.portfolio_value = 100000 + sum(
            position * ((max(bids.keys()) + min(asks.keys())) / 2)
            for product, position in state.position.items()
            if product in state.order_depths and (bids := state.order_depths[product].buy_orders) and (asks := state.order_depths[product].sell_orders)
        )

    def _serialize_state(self) -> str:
        """Serialize state for future ticks"""
        return json.dumps({'kelp_prices': list(self.kelp_prices), 'resin_spreads': list(self.resin_spread_history), 'indicators': self.kelp_indicators})