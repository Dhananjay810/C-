from typing import Dict, List
from datamodel import OrderDepth, TradingState, Order
import pandas as pd
import numpy as np

class Trader:
    def __init__(self):
        self.position_limits = {
            "SQUID_INK": 50, "PICNIC_BASKET1": 50, "PICNIC_BASKET2": 50,
            "RAINFOREST_RESIN": 50, "KELP": 50, "CROISSANTS": 50,
            "JAMS": 50, "DJEMBES": 50, "VOLCANIC_ROCK": 400,
            "VOLCANIC_ROCK_VOUCHER_9500": 200, "VOLCANIC_ROCK_VOUCHER_9750": 200,
            "VOLCANIC_ROCK_VOUCHER_10000": 200, "VOLCANIC_ROCK_VOUCHER_10250": 200,
            "VOLCANIC_ROCK_VOUCHER_10500": 200, "MAGNIFICENT_MACARONS": 75
        }
        self.conversion_limits = {
            "MAGNIFICENT_MACARONS": 10
        }
        self.positions = {product: 0 for product in self.position_limits}
        self.fair_values = {product: None for product in self.position_limits}
        self.voucher_details = {
            "VOLCANIC_ROCK_VOUCHER_9500": {"strike": 9500, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_9750": {"strike": 9750, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10000": {"strike": 10000, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10250": {"strike": 10250, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10500": {"strike": 10500, "days_left": 7}
        }
        self.macaron_factors = {
            'sunlight_hours': 0,
            'sugar_price': 0,
            'shipping_cost': 0,
            'import_tariff': 0,
            'export_tariff': 0,
            'storage_space': 0
        }
        self.round = 0
        self.macaron_price_history = []
        self.macaron_factor_history = []

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
                self.macaron_price_history.append(self.fair_values[product])

    def update_macaron_factors(self, state: TradingState):
        """Update the factors affecting MAGNIFICENT_MACARONS price"""
        if hasattr(state, 'observations'):
            obs = state.observations
            # Check if observations is a dictionary-like object
            if hasattr(obs, 'get'):
                for factor in self.macaron_factors:
                    if factor in obs:
                        self.macaron_factors[factor] = obs[factor]
                        if factor == 'sunlight_hours':
                            # Normalize sunlight hours to 0-1 range (assuming max 24 hours)
                            self.macaron_factors[factor] = min(24, max(0, obs[factor])) / 24
                        elif factor == 'storage_space':
                            # Normalize storage space (assuming 0-100 range)
                            self.macaron_factors[factor] = min(100, max(0, obs[factor])) / 100
            
                # Store factor values for analysis
                self.macaron_factor_history.append(self.macaron_factors.copy())

    def calculate_macaron_value(self) -> float:
        """Calculate theoretical value of MAGNIFICENT_MACARONS based on factors"""
        if not self.macaron_price_history:
            return None
            
        # Simple linear regression approach (could be enhanced)
        current_price = self.macaron_price_history[-1]
        
        # Calculate weighted impact of each factor
        # These weights would ideally be learned from historical data
        weights = {
            'sunlight_hours': 50,    # More sunlight -> higher quality
            'sugar_price': -30,     # Higher sugar price -> higher costs
            'shipping_cost': -20,    # Higher shipping -> higher costs
            'import_tariff': -15,    # Higher tariffs -> higher costs
            'export_tariff': -15,    # Higher tariffs -> higher costs
            'storage_space': 10      # More storage -> better preservation
        }
        
        adjustment = 0
        for factor, weight in weights.items():
            adjustment += self.macaron_factors[factor] * weight
            
        return current_price + adjustment

    def calculate_voucher_value(self, voucher: str, rock_price: float) -> float:
        """Calculate theoretical value of voucher based on underlying rock price"""
        if rock_price is None:
            return None
            
        strike = self.voucher_details[voucher]["strike"]
        days_left = self.voucher_details[voucher]["days_left"]
        
        # Simple intrinsic value calculation (could be enhanced with time value)
        intrinsic_value = max(0, rock_price - strike)
        
        # Discount for time remaining (linear discount for simplicity)
        time_factor = days_left / 7  # Full value at day 7, zero at expiration
        return intrinsic_value * time_factor

    def run(self, state: TradingState) -> (Dict[str, List[Order]], int, str):
        self.round += 1
        result = {}
        conversions = 0
        trader_data = ""

        # Update positions
        for product in self.positions:
            self.positions[product] = state.position.get(product, 0)

        # Update days left for vouchers
        for voucher in self.voucher_details:
            if voucher in self.voucher_details:
                self.voucher_details[voucher]["days_left"] = max(0, 7 - self.round + 1)

        # Update fair values for all products
        for product in state.order_depths:
            self.update_fair_value(product, state)

        # Update macaron factors
        self.update_macaron_factors(state)

        # Get volcanic rock price if available
        rock_price = self.fair_values.get("VOLCANIC_ROCK", None)

        # Trade MAGNIFICENT_MACARONS
        if "MAGNIFICENT_MACARONS" in state.order_depths:
            product = "MAGNIFICENT_MACARONS"
            order_depth = state.order_depths[product]
            current_position = self.positions[product]
            position_limit = self.position_limits[product]
            conversion_limit = self.conversion_limits.get(product, 0)
            orders = []
            
            # Calculate theoretical value
            macaron_value = self.calculate_macaron_value()
            if macaron_value is None:
                macaron_value = self.fair_values.get(product, 0)
            
            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            best_bid = buy_orders[0][0] if buy_orders else None
            best_ask = sell_orders[0][0] if sell_orders else None
            best_bid_qty = buy_orders[0][1] if buy_orders else 0
            best_ask_qty = sell_orders[0][1] if sell_orders else 0

            # Market making for macarons with dynamic spread
            spread = max(2, int(0.01 * macaron_value))  # At least 2, proportional to value
            
            # Adjust spread based on volatility (if we have enough history)
            if len(self.macaron_price_history) > 5:
                recent_prices = self.macaron_price_history[-5:]
                volatility = np.std(recent_prices)
                spread = max(2, int(spread + volatility))
            
            our_bid = max(1, int(macaron_value - spread))
            our_ask = int(macaron_value + spread)

            # Post bids (buy orders)
            if current_position < position_limit and best_ask and our_bid >= best_ask:
                qty_to_buy = min(best_ask_qty, position_limit - current_position)
                if qty_to_buy > 0:
                    orders.append(Order(product, best_ask, qty_to_buy))
            elif current_position < position_limit:
                # Post our bid if we have room
                orders.append(Order(product, our_bid, position_limit - current_position))

            # Post asks (sell orders)
            if current_position > -position_limit and best_bid and our_ask <= best_bid:
                qty_to_sell = min(best_bid_qty, current_position + position_limit)
                if qty_to_sell > 0:
                    orders.append(Order(product, best_bid, -qty_to_sell))
            elif current_position > -position_limit:
                # Post our ask if we have room
                orders.append(Order(product, our_ask, -(position_limit + current_position)))

            if orders:
                result[product] = orders

            # Handle conversions if needed (example logic)
            if current_position > position_limit - conversion_limit:
                conversions = min(conversion_limit, current_position - (position_limit - conversion_limit))
            elif current_position < -position_limit + conversion_limit:
                conversions = max(-conversion_limit, current_position + (position_limit - conversion_limit))

        # Trade vouchers based on their theoretical value
        for voucher in self.voucher_details:
            if voucher not in state.order_depths:
                continue
                
            order_depth = state.order_depths[voucher]
            current_position = self.positions[voucher]
            position_limit = self.position_limits[voucher]
            orders = []
            
            # Calculate theoretical value
            voucher_value = self.calculate_voucher_value(voucher, rock_price)
            if voucher_value is None:
                continue
                
            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            best_bid = buy_orders[0][0] if buy_orders else None
            best_ask = sell_orders[0][0] if sell_orders else None
            best_bid_qty = buy_orders[0][1] if buy_orders else 0
            best_ask_qty = sell_orders[0][1] if sell_orders else 0

            # Market making for vouchers
            spread = 2  # Small spread for market making
            our_bid = max(1, int(voucher_value - spread))
            our_ask = int(voucher_value + spread)

            # Post bids (buy orders)
            if current_position < position_limit and best_ask and our_bid >= best_ask:
                qty_to_buy = min(best_ask_qty, position_limit - current_position)
                if qty_to_buy > 0:
                    orders.append(Order(voucher, best_ask, qty_to_buy))
            elif current_position < position_limit:
                # Post our bid if we have room
                orders.append(Order(voucher, our_bid, position_limit - current_position))

            # Post asks (sell orders)
            if current_position > -position_limit and best_bid and our_ask <= best_bid:
                qty_to_sell = min(best_bid_qty, current_position + position_limit)
                if qty_to_sell > 0:
                    orders.append(Order(voucher, best_bid, -qty_to_sell))
            elif current_position > -position_limit:
                # Post our ask if we have room
                orders.append(Order(voucher, our_ask, -(position_limit + current_position)))

            if orders:
                result[voucher] = orders

        # Also trade the underlying volcanic rock
        if "VOLCANIC_ROCK" in state.order_depths:
            product = "VOLCANIC_ROCK"
            order_depth = state.order_depths[product]
            orders = []
            current_position = self.positions[product]
            position_limit = self.position_limits[product]
            fair_value = self.fair_values.get(product, None)
            
            if fair_value is not None:
                buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
                sell_orders = sorted(order_depth.sell_orders.items())
                best_bid = buy_orders[0][0] if buy_orders else None
                best_ask = sell_orders[0][0] if sell_orders else None
                best_bid_qty = buy_orders[0][1] if buy_orders else 0
                best_ask_qty = sell_orders[0][1] if sell_orders else 0

                # Simple market making for volcanic rock
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