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
            "SQUID_INK": 100,
            "CROISSANTS": 100,
            "JAMS": 100,
            "VOLCANIC_ROCK_VOUCHER_10000": 100,
            "KELP": 100,
            "VOLCANIC_ROCK_VOUCHER_10250": 100,
            "DJEMBES": 100,
            "VOLCANIC_ROCK_VOUCHER_10500": 100,
            "VOLCANIC_ROCK_VOUCHER_9750": 100,
            "PICNIC_BASKET1": 100,
            "PICNIC_BASKET2": 100,
            "VOLCANIC_ROCK_VOUCHER_9500": 100,
            "RAINFOREST_RESIN": 100,
            "MAGNIFICENT_MACARONS": 100,
            "VOLCANIC_ROCK": 100
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

    def calculate_fair_value(self, product: str) -> Optional[float]:
        """Calculate fair value using moving average"""
        if len(self.price_history[product]) < 5:  # Reduced from 20 to 5 for faster adaptation
            return None
        return statistics.mean(self.price_history[product][-5:])

    def calculate_bollinger_bands(self, product: str, window=20, num_std=2):
        """Calculate Bollinger Bands for a product"""
        if len(self.price_history[product]) < window:
            return None, None, None
            
        prices = self.price_history[product][-window:]
        moving_avg = statistics.mean(prices)
        std_dev = statistics.stdev(prices)
        upper_band = moving_avg + num_std * std_dev
        lower_band = moving_avg - num_std * std_dev
        
        return moving_avg, upper_band, lower_band

    def trade_product(self, product: str, state: TradingState) -> List[Order]:
        """Generic trading strategy for a product"""
        if product not in state.order_depths:
            return []
            
        order_depth = state.order_depths[product]
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        max_position = int(position_limit * self.max_position_ratio)
        
        # Calculate fair value
        fair_value = self.calculate_fair_value(product)
        if fair_value is None:
            return []
            
        # Get market prices
        best_bid = max(order_depth.buy_orders.keys()) if order_depth.buy_orders else None
        best_ask = min(order_depth.sell_orders.keys()) if order_depth.sell_orders else None
        
        if not best_bid or not best_ask:
            return []
            
        # Calculate Bollinger Bands
        moving_avg, upper_band, lower_band = self.calculate_bollinger_bands(product)
        if moving_avg is None:
            moving_avg = fair_value
            upper_band = fair_value * 1.05
            lower_band = fair_value * 0.95
        
        # Generate orders
        orders = []
        current_price = (best_bid + best_ask) / 2
        
        # Mean reversion strategy
        if current_price > upper_band:
            # Overbought - sell if we're not already short
            if current_position > -max_position:
                sell_qty = min(
                    abs(order_depth.buy_orders[best_bid]),
                    max_position + current_position
                )
                if sell_qty > 0:
                    orders.append(Order(product, best_bid, -sell_qty))
                    
        elif current_price < lower_band:
            # Oversold - buy if we're not already long
            if current_position < max_position:
                buy_qty = min(
                    abs(order_depth.sell_orders[best_ask]),
                    max_position - current_position
                )
                if buy_qty > 0:
                    orders.append(Order(product, best_ask, buy_qty))
        
        # Market making - only if we're not at position limits
        if abs(current_position) < max_position:
            spread = max(1, int(0.01 * fair_value))  # 1% spread
            our_bid = max(1, int(fair_value - spread))
            our_ask = int(fair_value + spread)
            
            # Adjust bid/ask based on our current position
            if current_position > 0:
                our_bid = max(1, int(our_bid * (1 - 0.005 * current_position)))
            elif current_position < 0:
                our_ask = int(our_ask * (1 + 0.005 * abs(current_position)))
            
            # Place orders
            bid_qty = min(5, max_position - current_position)
            ask_qty = min(5, max_position + current_position)
            
            if bid_qty > 0:
                orders.append(Order(product, our_bid, bid_qty))
            if ask_qty > 0:
                orders.append(Order(product, our_ask, -ask_qty))
        
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
            if product in state.order_depths:
                product_orders = self.trade_product(product, state)
                if product_orders:
                    result[product] = product_orders
        
        # Special strategy for PICNIC_BASKET1 and PICNIC_BASKET2
        if "PICNIC_BASKET1" in state.order_depths and "PICNIC_BASKET2" in state.order_depths:
            basket1_depth = state.order_depths["PICNIC_BASKET1"]
            basket2_depth = state.order_depths["PICNIC_BASKET2"]
            
            if basket1_depth.buy_orders and basket1_depth.sell_orders and basket2_depth.buy_orders and basket2_depth.sell_orders:
                basket1_best_bid = max(basket1_depth.buy_orders.keys())
                basket1_best_ask = min(basket1_depth.sell_orders.keys())
                basket2_best_bid = max(basket2_depth.buy_orders.keys())
                basket2_best_ask = min(basket2_depth.sell_orders.keys())
                
                # Calculate spread between the two baskets
                spread = (basket1_best_bid - basket2_best_ask) / ((basket1_best_bid + basket2_best_ask)/2)
                
                if spread > 0.01:  # If spread is more than 1%
                    # Buy the cheaper basket, sell the more expensive one
                    qty = min(
                        abs(basket2_depth.sell_orders[basket2_best_ask]),
                        abs(basket1_depth.buy_orders[basket1_best_bid]),
                        self.position_limits["PICNIC_BASKET1"] - self.positions["PICNIC_BASKET1"],
                        self.position_limits["PICNIC_BASKET2"] + self.positions["PICNIC_BASKET2"]
                    )
                    
                    if qty > 0:
                        if "PICNIC_BASKET1" not in result:
                            result["PICNIC_BASKET1"] = []
                        if "PICNIC_BASKET2" not in result:
                            result["PICNIC_BASKET2"] = []
                            
                        result["PICNIC_BASKET1"].append(Order("PICNIC_BASKET1", basket1_best_bid, -qty))
                        result["PICNIC_BASKET2"].append(Order("PICNIC_BASKET2", basket2_best_ask, qty))
        
        return result, 0, ""