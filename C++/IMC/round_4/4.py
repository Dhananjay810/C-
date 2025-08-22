from typing import Dict, List
from datamodel import OrderDepth, TradingState, Order
import pandas as pd
import numpy as np
import statistics

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
        self.positions = {product: 0 for product in self.position_limits}
        self.fair_values = {product: None for product in self.position_limits}
        self.price_history = {product: [] for product in self.position_limits}
        self.spreads = {product: 1 for product in self.position_limits}  # Default spread
        
        # Volcanic Rock Voucher details
        self.voucher_details = {
            "VOLCANIC_ROCK_VOUCHER_9500": {"strike": 9500, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_9750": {"strike": 9750, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10000": {"strike": 10000, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10250": {"strike": 10250, "days_left": 7},
            "VOLCANIC_ROCK_VOUCHER_10500": {"strike": 10500, "days_left": 7}
        }
        
        # Products that tend to move together (for pairs trading)
        self.correlated_products = {
            "PICNIC_BASKET1": ["PICNIC_BASKET2"],
            "VOLCANIC_ROCK": list(self.voucher_details.keys())
        }
        
        self.round = 0

    def update_fair_value(self, product: str, state: TradingState):
        if product not in state.order_depths:
            return
            
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        
        if buy_orders and sell_orders:
            best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
            self.fair_values[product] = (best_bid + best_ask) / 2
            self.price_history[product].append(self.fair_values[product])
            
            # Update spread based on current market
            self.spreads[product] = best_ask - best_bid

    def calculate_voucher_value(self, voucher: str, rock_price: float) -> float:
        """Calculate theoretical value of voucher based on underlying rock price"""
        if rock_price is None:
            return None
            
        strike = self.voucher_details[voucher]["strike"]
        days_left = self.voucher_details[voucher]["days_left"]
        
        # Simple intrinsic value calculation
        intrinsic_value = max(0, rock_price - strike)
        
        # Time value adjustment (linear decay)
        time_factor = days_left / 7
        return intrinsic_value * time_factor

    def calculate_volatility(self, product: str, window=5) -> float:
        """Calculate recent price volatility for a product"""
        if len(self.price_history[product]) < window:
            return 0
        recent_prices = self.price_history[product][-window:]
        return statistics.stdev(recent_prices)

    def should_arbitrage(self, product1: str, product2: str) -> bool:
        """Check if arbitrage opportunity exists between correlated products"""
        if (self.fair_values.get(product1) is None or 
            self.fair_values.get(product2) is None):
            return False
            
        price_ratio = self.fair_values[product1] / self.fair_values[product2]
        historical_ratio = self.get_historical_ratio(product1, product2)
        
        if historical_ratio is None:
            return False
            
        # Arbitrage if current ratio deviates significantly from historical
        return abs(price_ratio - historical_ratio) > 0.05  # 5% threshold

    def get_historical_ratio(self, product1: str, product2: str, window=10) -> float:
        """Get average price ratio between two products over historical window"""
        if (len(self.price_history[product1]) < window or 
            len(self.price_history[product2]) < window):
            return None
            
        ratios = []
        for p1, p2 in zip(self.price_history[product1][-window:], 
                         self.price_history[product2][-window:]):
            ratios.append(p1 / p2)
            
        return statistics.mean(ratios)

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

        # Get volcanic rock price if available
        rock_price = self.fair_values.get("VOLCANIC_ROCK", None)

        # Strategy 1: Market making for all products with dynamic spreads
        for product in state.order_depths:
            order_depth = state.order_depths[product]
            current_position = self.positions[product]
            position_limit = self.position_limits[product]
            orders = []
            
            if not order_depth.buy_orders or not order_depth.sell_orders:
                continue
                
            best_bid = max(order_depth.buy_orders.keys())
            best_ask = min(order_depth.sell_orders.keys())
            best_bid_qty = order_depth.buy_orders[best_bid]
            best_ask_qty = order_depth.sell_orders[best_ask]
            
            # Calculate fair value if not already set
            if self.fair_values.get(product) is None:
                self.fair_values[product] = (best_bid + best_ask) / 2
                
            fair_value = self.fair_values[product]
            volatility = self.calculate_volatility(product)
            
            # Adjust spread based on volatility and position
            spread = max(1, int(0.5 * volatility + 0.1 * abs(current_position)))
            our_bid = max(1, int(fair_value - spread))
            our_ask = int(fair_value + spread)
            
            # More aggressive pricing if we want to reduce position
            if current_position > position_limit * 0.7:
                our_bid -= 1
                our_ask -= 1
            elif current_position < -position_limit * 0.7:
                our_bid += 1
                our_ask += 1

            # Post bids (buy orders)
            if current_position < position_limit:
                # Take best ask if it's below our bid
                if best_ask <= our_bid:
                    qty_to_buy = min(best_ask_qty, position_limit - current_position)
                    if qty_to_buy > 0:
                        orders.append(Order(product, best_ask, qty_to_buy))
                else:
                    # Post our bid if we have room
                    orders.append(Order(product, our_bid, position_limit - current_position))

            # Post asks (sell orders)
            if current_position > -position_limit:
                # Take best bid if it's above our ask
                if best_bid >= our_ask:
                    qty_to_sell = min(best_bid_qty, current_position + position_limit)
                    if qty_to_sell > 0:
                        orders.append(Order(product, best_bid, -qty_to_sell))
                else:
                    # Post our ask if we have room
                    orders.append(Order(product, our_ask, -(position_limit + current_position)))

            if orders:
                result[product] = orders

        # Strategy 2: Volcanic Rock Voucher arbitrage
        if rock_price is not None:
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
                    
                best_bid = max(order_depth.buy_orders.keys()) if order_depth.buy_orders else None
                best_ask = min(order_depth.sell_orders.keys()) if order_depth.sell_orders else None
                best_bid_qty = order_depth.buy_orders[best_bid] if best_bid else 0
                best_ask_qty = order_depth.sell_orders[best_ask] if best_ask else 0

                # Determine if voucher is mispriced
                if best_ask and voucher_value > best_ask * 1.05:  # Undervalued by 5%
                    qty_to_buy = min(best_ask_qty, position_limit - current_position)
                    if qty_to_buy > 0:
                        orders.append(Order(voucher, best_ask, qty_to_buy))
                        
                elif best_bid and voucher_value < best_bid * 0.95:  # Overvalued by 5%
                    qty_to_sell = min(best_bid_qty, current_position + position_limit)
                    if qty_to_sell > 0:
                        orders.append(Order(voucher, best_bid, -qty_to_sell))

                if orders:
                    result[voucher] = orders

        # Strategy 3: Pairs trading for correlated products
        for product, correlated in self.correlated_products.items():
            if product not in state.order_depths:
                continue
                
            for other_product in correlated:
                if other_product not in state.order_depths:
                    continue
                    
                if self.should_arbitrage(product, other_product):
                    # Determine which product is over/under valued
                    current_ratio = self.fair_values[product] / self.fair_values[other_product]
                    historical_ratio = self.get_historical_ratio(product, other_product)
                    
                    if current_ratio > historical_ratio * 1.05:
                        # product is overvalued, other_product is undervalued
                        # Sell product and buy other_product
                        order_depth = state.order_depths[product]
                        best_bid = max(order_depth.buy_orders.keys())
                        best_bid_qty = order_depth.buy_orders[best_bid]
                        qty = min(best_bid_qty, self.position_limits[product] - self.positions[product])
                        if qty > 0:
                            result.setdefault(product, []).append(Order(product, best_bid, -qty))
                            
                        order_depth = state.order_depths[other_product]
                        best_ask = min(order_depth.sell_orders.keys())
                        best_ask_qty = order_depth.sell_orders[best_ask]
                        qty = min(best_ask_qty, self.position_limits[other_product] - self.positions[other_product])
                        if qty > 0:
                            result.setdefault(other_product, []).append(Order(other_product, best_ask, qty))
                            
                    elif current_ratio < historical_ratio * 0.95:
                        # product is undervalued, other_product is overvalued
                        # Buy product and sell other_product
                        order_depth = state.order_depths[product]
                        best_ask = min(order_depth.sell_orders.keys())
                        best_ask_qty = order_depth.sell_orders[best_ask]
                        qty = min(best_ask_qty, self.position_limits[product] - self.positions[product])
                        if qty > 0:
                            result.setdefault(product, []).append(Order(product, best_ask, qty))
                            
                        order_depth = state.order_depths[other_product]
                        best_bid = max(order_depth.buy_orders.keys())
                        best_bid_qty = order_depth.buy_orders[best_bid]
                        qty = min(best_bid_qty, self.position_limits[other_product] - self.positions[other_product])
                        if qty > 0:
                            result.setdefault(other_product, []).append(Order(other_product, best_bid, -qty))

        return result, conversions, trader_data