from typing import Dict, List, Optional
from datamodel import OrderDepth, TradingState, Order
import pandas as pd
import numpy as np
import statistics
from collections import defaultdict

# Define OwnTrade class if it's not in datamodel.py
class OwnTrade:
    def __init__(self, timestamp: int, trade_id: int, price: int, quantity: int, side: str, counter_party: str):
        self.timestamp = timestamp
        self.trade_id = trade_id
        self.price = price
        self.quantity = quantity
        self.side = side
        self.counter_party = counter_party

class Trader:
    def __init__(self):
        # Position limits including MAGNIFICENT_MACARONS
        self.position_limits = {
            "SQUID_INK": 50, "PICNIC_BASKET1": 50, "PICNIC_BASKET2": 50,
            "RAINFOREST_RESIN": 50, "KELP": 50, "CROISSANTS": 50,
            "JAMS": 50, "DJEMBES": 50, "VOLCANIC_ROCK": 400,
            "VOLCANIC_ROCK_VOUCHER_9500": 200, "VOLCANIC_ROCK_VOUCHER_9750": 200,
            "VOLCANIC_ROCK_VOUCHER_10000": 200, "VOLCANIC_ROCK_VOUCHER_10250": 200,
            "VOLCANIC_ROCK_VOUCHER_10500": 200, "MAGNIFICENT_MACARONS": 75
        }
        
        # Conversion limit for MAGNIFICENT_MACARONS
        self.conversion_limits = {
            "MAGNIFICENT_MACARONS": 10
        }
        
        # Initialize positions
        self.positions = {product: 0 for product in self.position_limits}
        
        # Price history for statistical analysis
        self.price_history = {product: [] for product in self.position_limits}
        self.spreads = {product: 0 for product in self.position_limits}
        
        # MACARON specific parameters
        self.critical_sunlight_index = 50  # Initial guess for CSI
        self.sunlight_history = []
        self.macaron_fair_value = None
        self.macaron_price_history = []
        
        # Counterparty tracking
        self.counterparty_history = defaultdict(list)
        
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
                    
                    # Special handling for MACARONS
                    if product == "MAGNIFICENT_MACARONS":
                        self.macaron_price_history.append(mid_price)
                        if len(self.macaron_price_history) > 20:
                            self.macaron_price_history.pop(0)

    # ... [rest of the methods remain the same until run()]

    def run(self, state: TradingState) -> (Dict[str, List[Order]], int, str):
        self.round += 1
        
        # Update our positions and price history
        self.update_positions(state)
        self.update_price_history(state)
        
        # Update sunlight index estimation
        self.update_sunlight_index(state)
        
        # Process counterparty information if available
        if state.own_trades:  # Changed from hasattr check
            self.process_counterparty_info(state.own_trades)
        
        # Execute trading strategies
        result = {}
        conversions = 0
        
        # Trade MAGNIFICENT_MACARONS with specialized strategy
        macaron_orders = self.trade_macarons(state)
        if macaron_orders:
            result["MAGNIFICENT_MACARONS"] = macaron_orders
        
        # Trade other products with standard strategy
        for product in self.position_limits:
            if product == "MAGNIFICENT_MACARONS":
                continue  # Already handled
                
            if product in state.order_depths:
                # Get counterparty behavior analysis
                cp_behavior = self.analyze_counterparty_behavior(product)
                
                order_depth = state.order_depths[product]
                current_position = self.positions[product]
                position_limit = self.position_limits[product]
                max_position = int(position_limit * self.max_position_ratio)
                
                # Calculate fair value
                if len(self.price_history[product]) >= 5:
                    fair_value = statistics.mean(self.price_history[product][-5:])
                else:
                    fair_value = None
                
                if fair_value is not None:
                    # Adjust strategy based on counterparty behavior
                    spread_adjustment = 1 + cp_behavior['aggressiveness']
                    inventory_adjustment = cp_behavior['inventory_imbalance']
                    
                    buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
                    sell_orders = sorted(order_depth.sell_orders.items())
                    best_bid = buy_orders[0][0] if buy_orders else None
                    best_ask = sell_orders[0][0] if sell_orders else None
                    best_bid_qty = buy_orders[0][1] if buy_orders else 0
                    best_ask_qty = sell_orders[0][1] if sell_orders else 0
                    
                    # Market making with adjusted spreads
                    spread = max(1, int(0.02 * fair_value * spread_adjustment))
                    our_bid = max(1, int(fair_value - spread + inventory_adjustment))
                    our_ask = int(fair_value + spread + inventory_adjustment)
                    
                    orders = []
                    
                    # Post bids (buy orders)
                    if current_position < max_position and best_ask and our_bid >= best_ask:
                        qty_to_buy = min(best_ask_qty, max_position - current_position)
                        if qty_to_buy > 0:
                            orders.append(Order(product, best_ask, qty_to_buy))
                    elif current_position < max_position:
                        # Post our bid if we have room
                        orders.append(Order(product, our_bid, max_position - current_position))
                    
                    # Post asks (sell orders)
                    if current_position > -max_position and best_bid and our_ask <= best_bid:
                        qty_to_sell = min(best_bid_qty, max_position + current_position)
                        if qty_to_sell > 0:
                            orders.append(Order(product, best_bid, -qty_to_sell))
                    elif current_position > -max_position:
                        # Post our ask if we have room
                        orders.append(Order(product, our_ask, -(max_position + current_position)))
                    
                    if orders:
                        result[product] = orders
        
        # Handle conversions for MAGNIFICENT_MACARONS if needed
        if "MAGNIFICENT_MACARONS" in self.positions:
            current_macaron_position = self.positions["MAGNIFICENT_MACARONS"]
            if abs(current_macaron_position) > self.position_limits["MAGNIFICENT_MACARONS"] - self.conversion_limits["MAGNIFICENT_MACARONS"]:
                conversions = min(
                    self.conversion_limits["MAGNIFICENT_MACARONS"],
                    abs(current_macaron_position) - (self.position_limits["MAGNIFICENT_MACARONS"] - self.conversion_limits["MAGNIFICENT_MACARONS"])
                )
                if current_macaron_position > 0:
                    conversions = -conversions  # Need to sell for conversions
        
        return result, conversions, ""