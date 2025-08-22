from typing import Dict, List
from datamodel import OrderDepth, TradingState, Order
import numpy as np
from collections import defaultdict

class Trader:
    def __init__(self):
        self.position_limits = {
            "SQUID_INK": 50, "PICNIC_BASKET1": 60, "PICNIC_BASKET2": 100,
            "RAINFOREST_RESIN": 50, "KELP": 50, "CROISSANTS": 250,
            "JAMS": 350, "DJEMBES": 60, "VOLCANIC_ROCK": 400,
            "VOLCANIC_ROCK_VOUCHER_9500": 200, "VOLCANIC_ROCK_VOUCHER_9750": 200,
            "VOLCANIC_ROCK_VOUCHER_10000": 200, "VOLCANIC_ROCK_VOUCHER_10250": 200,
            "VOLCANIC_ROCK_VOUCHER_10500": 200,
            "MAGNIFICENT_MACARONS": 75  # Added position limit for new product
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
        self.price_history = defaultdict(list)
        self.round = 0
        self.squid_ink_window = 20
        self.squid_ink_z_threshold = 2.0  # High for safety
        self.mean_window = 5  # Short for RESIN, KELP
        self.trade_qty = 3  # Small for zero risk
        self.basket_qty = 2  # Smaller for arbitrage
        self.basket_components = {
            "PICNIC_BASKET1": {"CROISSANTS": 6, "JAMS": 3, "DJEMBES": 1},
            "PICNIC_BASKET2": {"CROISSANTS": 4, "JAMS": 2}
        }
        
        # Parameters for MAGNIFICENT_MACARONS
        self.macaron_window = 10  # Lookback window for price history
        self.macaron_spread = 3  # Acceptable spread for trading
        self.macaron_conversion_limit = 10  # Conversion limit
        self.macaron_trade_qty = 5  # Default trade quantity

    def update_positions(self, state: TradingState):
        for product in self.positions:
            self.positions[product] = state.position.get(product, 0)

    def update_price_history(self, state: TradingState):
        for product in state.order_depths:
            order_depth = state.order_depths[product]
            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            if buy_orders and sell_orders:
                best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
                mid_price = (best_bid + best_ask) / 2
                self.price_history[product].append(mid_price)
                max_window = max(self.squid_ink_window, self.mean_window, self.macaron_window)
                if len(self.price_history[product]) > max_window:
                    self.price_history[product] = self.price_history[product][-max_window:]

    def update_fair_value(self, product: str, state: TradingState):
        if product not in state.order_depths:
            return
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        if buy_orders and sell_orders:
            best_bid, best_ask = buy_orders[0][0], sell_orders[0][0]
            self.fair_values[product] = (best_bid + best_ask) / 2

    def calculate_macaron_value(self, state: TradingState) -> float:
        """Calculate fair value for MAGNIFICENT_MACARONS based on various factors"""
        if "MAGNIFICENT_MACARONS" not in state.order_depths:
            return None
            
        # Get current macaron price
        order_depth = state.order_depths["MAGNIFICENT_MACARONS"]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        if not buy_orders or not sell_orders:
            return None
            
        current_mid = (buy_orders[0][0] + sell_orders[0][0]) / 2
        
        # Simple mean reversion strategy with volatility adjustment
        if len(self.price_history["MAGNIFICENT_MACARONS"]) >= self.macaron_window:
            prices = np.array(self.price_history["MAGNIFICENT_MACARONS"][-self.macaron_window:])
            mean_price = np.mean(prices)
            std_price = np.std(prices)
            
            # If price is more than 1 std away from mean, adjust towards mean
            if current_mid > mean_price + std_price:
                return mean_price + std_price * 0.5
            elif current_mid < mean_price - std_price:
                return mean_price - std_price * 0.5
            else:
                return current_mid
        else:
            return current_mid

    def trade_magnificent_macarons(self, state: TradingState) -> List[Order]:
        product = "MAGNIFICENT_MACARONS"
        orders = []
        
        if product not in state.order_depths:
            return orders
            
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        fair_value = self.calculate_macaron_value(state)
        
        if fair_value is None:
            return orders
            
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        
        best_bid = buy_orders[0][0] if buy_orders else None
        best_ask = sell_orders[0][0] if sell_orders else None
        best_bid_qty = buy_orders[0][1] if buy_orders else 0
        best_ask_qty = sell_orders[0][1] if sell_orders else 0
        
        # Calculate acceptable buy/sell prices with spread
        acceptable_buy_price = fair_value - self.macaron_spread
        acceptable_sell_price = fair_value + self.macaron_spread
        
        # Buy if ask price is good and we have room
        if (best_ask and best_ask <= acceptable_buy_price and 
            current_position < position_limit):
            qty = min(best_ask_qty, position_limit - current_position, self.macaron_trade_qty)
            if qty > 0:
                orders.append(Order(product, best_ask, qty))
                
        # Sell if bid price is good and we have room
        if (best_bid and best_bid >= acceptable_sell_price and 
            current_position > -position_limit):
            qty = min(best_bid_qty, position_limit + current_position, self.macaron_trade_qty)
            if qty > 0:
                orders.append(Order(product, best_bid, -qty))
                
        # Post passive orders if we didn't trade aggressively
        if not orders:
            if current_position < position_limit:
                orders.append(Order(product, acceptable_buy_price, self.macaron_trade_qty))
            if current_position > -position_limit:
                orders.append(Order(product, acceptable_sell_price, -self.macaron_trade_qty))
                
        return orders

    # ... [rest of your existing methods remain unchanged] ...

    def run(self, state: TradingState) -> (Dict[str, List[Order]], int, str):
        self.round += 1
        result = {}
        conversions = 0
        trader_data = ""

        self.update_positions(state)
        self.update_price_history(state)
        for product in state.order_depths:
            self.update_fair_value(product, state)

        # Add trading for MAGNIFICENT_MACARONS
        macaron_orders = self.trade_magnificent_macarons(state)
        if macaron_orders:
            result["MAGNIFICENT_MACARONS"] = macaron_orders

        voucher_orders = self.trade_vouchers(state)
        result.update(voucher_orders)

        rock_orders = self.trade_volcanic_rock(state)
        if rock_orders:
            result["VOLCANIC_ROCK"] = rock_orders

        squid_ink_orders = self.trade_squid_ink(state)
        if squid_ink_orders:
            result["SQUID_INK"] = squid_ink_orders

        resin_orders = self.trade_rainforest_resin(state)
        if resin_orders:
            result["RAINFOREST_RESIN"] = resin_orders

        kelp_orders = self.trade_kelp(state)
        if kelp_orders:
            result["KELP"] = kelp_orders

        basket_orders = self.trade_baskets(state)
        result.update(basket_orders)

        for voucher in self.voucher_details:
            self.voucher_details[voucher]["days_left"] = max(0, 7 - self.round + 1)

        return result, conversions, trader_data