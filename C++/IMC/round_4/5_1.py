from typing import Dict, List
from datamodel import OrderDepth, TradingState, Order
import pandas as pd
import numpy as np
from statistics import mean

class Trader:
    def __init__(self):
        self.position_limits = {
            "SQUID_INK": 50, "PICNIC_BASKET1": 50, "PICNIC_BASKET2": 50,
            "RAINFOREST_RESIN": 50, "KELP": 50, "CROISSANTS": 50,
            "JAMS": 50, "DJEMBES": 50, "MAGNIFICENT_MACARONS": 75,
            "VOLCANIC_ROCK": 50  # Added missing product
        }
        self.positions = {product: 0 for product in self.position_limits}
        self.fair_values = {product: None for product in self.position_limits}
        self.macarons_conversion_limit = 10
        self.macarons_price_history = []
        self.macarons_factor_history = {
            'sunlight': [],
            'sugar': [],
            'shipping': [],
            'tariffs': [],
            'storage': []
        }

    def update_fair_value(self, product: str, state: TradingState):
        if product not in state.order_depths:
            return
            
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        if buy_orders and sell_orders:
            best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
            self.fair_values[product] = (best_bid + best_ask) / 2
            if product == "MAGNIFICENT_MACARONS":
                self.macarons_price_history.append(self.fair_values[product])
                if len(self.macarons_price_history) > 100:
                    self.macarons_price_history.pop(0)

    def analyze_macarons_factors(self, observations):
        """Analyze external factors and return a score between -1 (bad) and 1 (good)"""
        if not observations:
            return 0
        
        # Get factor values (assuming observations has these attributes)
        factors = {
            'sunlight': getattr(observations, 'SUNLIGHT', 50),
            'sugar': getattr(observations, 'SUGAR', 50),
            'shipping': getattr(observations, 'SHIPPING', 50),
            'tariffs': getattr(observations, 'TARIFFS', 50),
            'storage': getattr(observations, 'STORAGE', 50)
        }
        
        # Update factor history
        for factor, value in factors.items():
            self.macarons_factor_history[factor].append(value)
            if len(self.macarons_factor_history[factor]) > 20:
                self.macarons_factor_history[factor].pop(0)
        
        # Calculate weighted score
        weights = {
            'sunlight': 0.3,    # More sunlight is good
            'sugar': -0.25,     # Higher sugar prices are bad
            'shipping': -0.2,   # Higher shipping costs are bad
            'tariffs': -0.15,   # Higher tariffs are bad
            'storage': 0.1      # More storage is good
        }
        
        # Normalize factors to 0-1 range and calculate score
        score = 0
        for factor, weight in weights.items():
            if self.macarons_factor_history[factor]:
                avg_value = mean(self.macarons_factor_history[factor])
                normalized = (avg_value - 0) / 100  # Assuming factors range 0-100
                score += weight * normalized
        
        return max(-1, min(1, score))  # Clamp between -1 and 1

    def get_macarons_strategy(self, state: TradingState):
        """Specialized trading strategy for MAGNIFICENT_MACARONS"""
        product = "MAGNIFICENT_MACARONS"
        if product not in state.order_depths:
            return []
            
        order_depth = state.order_depths[product]
        current_position = self.positions.get(product, 0)
        position_limit = self.position_limits.get(product, 0)
        orders = []
        
        # Analyze market conditions
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        best_bid = buy_orders[0][0] if buy_orders else None
        best_ask = sell_orders[0][0] if sell_orders else None
        best_bid_qty = buy_orders[0][1] if buy_orders else 0
        best_ask_qty = sell_orders[0][1] if sell_orders else 0
        
        # Get external factor score
        factor_score = self.analyze_macarons_factors(state.observations)
        
        # Calculate fair value with factor adjustment
        if self.fair_values.get(product) is not None:
            fair_value = self.fair_values[product] * (1 + factor_score * 0.1)
        else:
            fair_value = None
            
        # Determine trading actions based on factors and price
        if fair_value is not None:
            # Aggressive buying when conditions are favorable
            if factor_score > 0.5 and best_ask and best_ask < fair_value:
                qty = min(best_ask_qty, position_limit - current_position)
                if qty > 0:
                    orders.append(Order(product, best_ask, qty))
            
            # Aggressive selling when conditions are unfavorable
            elif factor_score < -0.5 and best_bid and best_bid > fair_value:
                qty = min(best_bid_qty, current_position + position_limit)
                if qty > 0:
                    orders.append(Order(product, best_bid, -qty))
            
            # Mean-reversion when conditions are neutral
            elif -0.2 <= factor_score <= 0.2:
                if best_ask and best_ask < fair_value * 0.98:
                    qty = min(best_ask_qty, position_limit - current_position)
                    if qty > 0:
                        orders.append(Order(product, best_ask, qty))
                if best_bid and best_bid > fair_value * 1.02:
                    qty = min(best_bid_qty, current_position + position_limit)
                    if qty > 0:
                        orders.append(Order(product, best_bid, -qty))
        
        return orders

    def run(self, state: TradingState) -> (Dict[str, List[Order]], int, str):
        result = {}
        conversions = 0
        trader_data = ""

        # Initialize positions with state positions or 0
        for product in self.position_limits:
            self.positions[product] = state.position.get(product, 0)

        for product in state.order_depths:
            # Skip products we don't have position limits for
            if product not in self.position_limits:
                continue
                
            self.update_fair_value(product, state)
            
            if product == "MAGNIFICENT_MACARONS":
                # Use specialized strategy for MACARONS
                macarons_orders = self.get_macarons_strategy(state)
                if macarons_orders:
                    result[product] = macarons_orders
                
                # Determine if we should use conversions
                factor_score = self.analyze_macarons_factors(state.observations)
                current_position = self.positions[product]
                
                # Convert to cover short position when conditions improve
                if factor_score > 0.7 and current_position < 0:
                    conversions = min(self.macarons_conversion_limit, -current_position)
                
                # Convert to reduce long position when conditions worsen
                elif factor_score < -0.7 and current_position > 0:
                    conversions = min(self.macarons_conversion_limit, current_position)
                    
                continue
            
            # Standard market-making for other products
            order_depth = state.order_depths[product]
            orders = []
            current_position = self.positions.get(product, 0)
            position_limit = self.position_limits.get(product, 0)
            fair_value = self.fair_values.get(product)
            if fair_value is None:
                continue

            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            best_bid = buy_orders[0][0] if buy_orders else None
            best_ask = sell_orders[0][0] if sell_orders else None
            best_bid_qty = buy_orders[0][1] if buy_orders else 0
            best_ask_qty = sell_orders[0][1] if sell_orders else 0

            # Market-making: place orders to capture spread
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