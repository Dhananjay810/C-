from typing import Dict, List
from datamodel import OrderDepth, TradingState, Order
import pandas as pd
import numpy as np
import statistics

class Trader:
    def __init__(self):
        # Position limits from the problem description
        self.position_limits = {
            "SQUID_INK": 50, "PICNIC_BASKET1": 50, "PICNIC_BASKET2": 50,
            "RAINFOREST_RESIN": 50, "KELP": 50, "CROISSANTS": 50,
            "JAMS": 50, "DJEMBES": 50, "VOLCANIC_ROCK": 400,
            "VOLCANIC_ROCK_VOUCHER_9500": 200, "VOLCANIC_ROCK_VOUCHER_9750": 200,
            "VOLCANIC_ROCK_VOUCHER_10000": 200, "VOLCANIC_ROCK_VOUCHER_10250": 200,
            "VOLCANIC_ROCK_VOUCHER_10500": 200, "MAGNIFICENT_MACARONS": 75
        }
        
        # Initialize positions
        self.positions = {product: 0 for product in self.position_limits}
        
        # Voucher details
        self.voucher_details = {
            "VOLCANIC_ROCK_VOUCHER_9500": {"strike": 9500, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_9750": {"strike": 9750, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10000": {"strike": 10000, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10250": {"strike": 10250, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10500": {"strike": 10500, "days_left": 7}
        }
        
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

    def calculate_voucher_value(self, voucher: str, rock_price: float) -> float:
        """Improved voucher pricing model"""
        if rock_price is None:
            return None
            
        strike = self.voucher_details[voucher]["strike"]
        days_left = self.voucher_details[voucher]["days_left"]
        
        # Intrinsic value
        intrinsic = max(0, rock_price - strike)
        
        # Time value decay (non-linear)
        if days_left > 0:
            time_value = intrinsic * (days_left / 7) ** 0.5  # Square root decay
        else:
            time_value = 0
            
        return intrinsic + time_value

    def calculate_macaron_value(self) -> float:
        """Calculate fair value for macarons using statistical analysis"""
        if len(self.price_history["MAGNIFICENT_MACARONS"]) < 20:
            return None
            
        # Use exponential moving average for more responsive fair value
        prices = pd.Series(self.price_history["MAGNIFICENT_MACARONS"])
        ema = prices.ewm(span=20).mean().iloc[-1]
        return ema

    def trade_vouchers(self, state: TradingState) -> Dict[str, List[Order]]:
        """Improved voucher trading strategy"""
        orders = {}
        rock_price = self.price_history.get("VOLCANIC_ROCK", [None])[-1]
        
        for voucher in self.voucher_details:
            if voucher not in state.order_depths:
                continue
                
            order_depth = state.order_depths[voucher]
            current_position = self.positions[voucher]
            position_limit = self.position_limits[voucher]
            max_position = position_limit * self.max_position_ratio
            
            # Calculate fair value
            fair_value = self.calculate_voucher_value(voucher, rock_price)
            if fair_value is None:
                continue
                
            # Get market prices
            best_bid = max(order_depth.buy_orders.keys()) if order_depth.buy_orders else None
            best_ask = min(order_depth.sell_orders.keys()) if order_depth.sell_orders else None
            
            # Determine our bid/ask prices
            spread = max(2, int(0.01 * fair_value))  # Dynamic spread
            our_bid = max(1, int(fair_value - spread))
            our_ask = int(fair_value + spread)
            
            # Calculate position-adjusted quantities
            bid_qty = min(5, int(max_position - current_position))
            ask_qty = min(5, int(max_position + current_position))
            
            # Generate orders
            voucher_orders = []
            
            # Buy if market price is below our valuation
            if best_ask and best_ask < fair_value * (1 - 0.005):  # 0.5% below fair value
                qty = min(abs(order_depth.sell_orders[best_ask]), bid_qty)
                if qty > 0:
                    voucher_orders.append(Order(voucher, best_ask, qty))
            
            # Sell if market price is above our valuation
            elif best_bid and best_bid > fair_value * (1 + 0.005):  # 0.5% above fair value
                qty = min(abs(order_depth.buy_orders[best_bid]), ask_qty)
                if qty > 0:
                    voucher_orders.append(Order(voucher, best_bid, -qty))
            
            # Market making when no clear opportunity
            else:
                if current_position < max_position:
                    voucher_orders.append(Order(voucher, our_bid, bid_qty))
                if current_position > -max_position:
                    voucher_orders.append(Order(voucher, our_ask, -ask_qty))
            
            if voucher_orders:
                orders[voucher] = voucher_orders
                
        return orders

    def trade_volcanic_rock(self, state: TradingState) -> Dict[str, List[Order]]:
        """Improved volcanic rock trading strategy"""
        if "VOLCANIC_ROCK" not in state.order_depths:
            return {}
            
        product = "VOLCANIC_ROCK"
        order_depth = state.order_depths[product]
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        max_position = position_limit * self.max_position_ratio
        
        # Calculate fair value as moving average
        if len(self.price_history[product]) < 20:
            return {}
            
        fair_value = statistics.mean(self.price_history[product][-20:])
        spread = self.spreads[product]
        
        # Get market prices
        best_bid = max(order_depth.buy_orders.keys()) if order_depth.buy_orders else None
        best_ask = min(order_depth.sell_orders.keys()) if order_depth.sell_orders else None
        
        # Determine our bid/ask prices
        our_bid = max(1, int(fair_value - spread/2))
        our_ask = int(fair_value + spread/2)
        
        # Calculate position-adjusted quantities
        bid_qty = min(10, int(max_position - current_position))
        ask_qty = min(10, int(max_position + current_position))
        
        # Generate orders
        orders = []
        
        # Buy if significantly below fair value
        if best_ask and best_ask < fair_value * 0.99:  # 1% below fair value
            qty = min(abs(order_depth.sell_orders[best_ask]), bid_qty)
            if qty > 0:
                orders.append(Order(product, best_ask, qty))
        
        # Sell if significantly above fair value
        elif best_bid and best_bid > fair_value * 1.01:  # 1% above fair value
            qty = min(abs(order_depth.buy_orders[best_bid]), ask_qty)
            if qty > 0:
                orders.append(Order(product, best_bid, -qty))
        
        # Market making when no clear opportunity
        else:
            if current_position < max_position:
                orders.append(Order(product, our_bid, bid_qty))
            if current_position > -max_position:
                orders.append(Order(product, our_ask, -ask_qty))
        
        return {product: orders} if orders else {}

    def trade_macarons(self, state: TradingState) -> (Dict[str, List[Order]], int):
        """Improved macaron trading strategy with conversions"""
        if "MAGNIFICENT_MACARONS" not in state.order_depths:
            return {}, 0
            
        product = "MAGNIFICENT_MACARONS"
        order_depth = state.order_depths[product]
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        max_position = position_limit * self.max_position_ratio
        
        # Calculate fair value
        fair_value = self.calculate_macaron_value()
        if fair_value is None:
            return {}, 0
            
        # Get market prices
        best_bid = max(order_depth.buy_orders.keys()) if order_depth.buy_orders else None
        best_ask = min(order_depth.sell_orders.keys()) if order_depth.sell_orders else None
        
        # Calculate Bollinger Bands for mean reversion
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
        conversions = 0
        
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
        
        # Handle conversions if position is too large
        if abs(current_position) > position_limit * 0.9:
            conversions = min(10, abs(current_position) - int(position_limit * 0.9))
            if current_position > 0:
                conversions = -conversions
        
        return ({product: orders} if orders else {}), conversions

    def run(self, state: TradingState) -> (Dict[str, List[Order]], int, str):
        self.round += 1
        
        # Update our positions and price history
        self.update_positions(state)
        self.update_price_history(state)
        
        # Execute trading strategies
        result = {}
        
        # Trade vouchers
        voucher_orders = self.trade_vouchers(state)
        result.update(voucher_orders)
        
        # Trade volcanic rock
        rock_orders = self.trade_volcanic_rock(state)
        result.update(rock_orders)
        
        # Trade macarons
        macaron_orders, conversions = self.trade_macarons(state)
        result.update(macaron_orders)
        
        return result, conversions, ""