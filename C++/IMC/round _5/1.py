from typing import Dict, List, Optional
from datamodel import OrderDepth, TradingState, Order
import pandas as pd
import numpy as np
import statistics
from collections import defaultdict

class Trader:
    def __init__(self):
        # Position limits from the problem description
        self.position_limits = {
            "PEARLS": 20,
            "BANANAS": 20,
            "COCONUTS": 600,
            "PINA_COLADAS": 300,
            "DIVING_GEAR": 50,
            "BERRIES": 250,
            "DOLPHIN_SIGHTINGS": 0,
            "BAGUETTE": 150,
            "DIP": 300,
            "UKULELE": 70,
            "PICNIC_BASKET": 70
        }
        
        # Initialize positions
        self.positions = {product: 0 for product in self.position_limits}
        
        # Price history for statistical analysis
        self.price_history = {product: [] for product in self.position_limits}
        self.spreads = {product: 0 for product in self.position_limits}
        
        # Risk management parameters
        self.max_position_ratio = 0.8  # Don't exceed 80% of position limit
        self.take_profit = 0.02  # 2% profit target
        self.stop_loss = 0.01  # 1% stop loss
        
        # Round counter
        self.round = 0

    def update_positions(self, state: TradingState):
        """Update our positions from the state"""
        for product in self.positions:
            self.positions[product] = state.position.get(product, 0)

    def update_price_history(self, state: TradingState):
        """Update price history for all products"""
        for product in state.order_depths:
            order_depth = state.order_depths[product]
            if order_depth.buy_orders and order_depth.sell_orders:
                best_bid = max(order_depth.buy_orders.keys())
                best_ask = min(order_depth.sell_orders.keys())
                mid_price = (best_bid + best_ask) / 2
                
                # Update price history (keep last 100 prices)
                if product in self.price_history:
                    self.price_history[product].append(mid_price)
                    if len(self.price_history[product]) > 100:
                        self.price_history[product].pop(0)
                    
                    # Update spread information
                    self.spreads[product] = best_ask - best_bid

    def calculate_fair_value(self, product: str) -> float:
        """Calculate fair value using moving average"""
        if len(self.price_history[product]) < 20:
            return None
        return statistics.mean(self.price_history[product][-20:])

    def trade_product(self, product: str, state: TradingState) -> List[Order]:
        """Generic trading strategy for a product"""
        if product not in state.order_depths:
            return []
            
        order_depth = state.order_depths[product]
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        max_position = position_limit * self.max_position_ratio
        
        # Calculate fair value
        fair_value = self.calculate_fair_value(product)
        if fair_value is None:
            return []
            
        # Get market prices
        best_bid = max(order_depth.buy_orders.keys()) if order_depth.buy_orders else None
        best_ask = min(order_depth.sell_orders.keys()) if order_depth.sell_orders else None
        
        # Calculate Bollinger Bands
        prices = self.price_history[product]
        if len(prices) >= 20:
            moving_avg = statistics.mean(prices[-20:])
            std_dev = statistics.stdev(prices[-20:])
            upper_band = moving_avg + 2 * std_dev
            lower_band = moving_avg - 2 * std_dev
        else:
            moving_avg = fair_value
            upper_band = fair_value * 1.05
            lower_band = fair_value * 0.95
        
        # Generate orders
        orders = []
        
        # Mean reversion strategy
        current_price = (best_bid + best_ask) / 2 if best_bid and best_ask else fair_value
        
        if current_price > upper_band and best_bid:
            # Overbought - sell
            qty = min(abs(order_depth.buy_orders[best_bid]), 
                     int(max_position + current_position))
            if qty > 0:
                orders.append(Order(product, best_bid, -qty))
                
        elif current_price < lower_band and best_ask:
            # Oversold - buy
            qty = min(abs(order_depth.sell_orders[best_ask]), 
                     int(max_position - current_position))
            if qty > 0:
                orders.append(Order(product, best_ask, qty))
                
        else:
            # Market making
            spread = max(2, int(0.02 * fair_value))  # 2% spread
            our_bid = max(1, int(fair_value - spread))
            our_ask = int(fair_value + spread)
            
            if current_position < max_position:
                orders.append(Order(product, our_bid, min(5, int(max_position - current_position))))
            if current_position > -max_position:
                orders.append(Order(product, our_ask, -min(5, int(max_position + current_position))))
        
        return orders

    def run(self, state: TradingState) -> (Dict[str, List[Order]], int, str):
        self.round += 1
        
        # Update our positions and price history
        self.update_positions(state)
        self.update_price_history(state)
        
        # Execute trading strategies
        result = {}
        
        # Trade each product
        for product in self.position_limits:
            product_orders = self.trade_product(product, state)
            if product_orders:
                result[product] = product_orders
        
        return result, 0, ""