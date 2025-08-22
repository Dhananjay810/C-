from datamodel import OrderDepth, TradingState, Order
from typing import Dict, List
import json
import numpy as np

class Trader:
    def __init__(self):
        # Position limits for all products
        self.position_limits = {
            "RAINFOREST_RESIN": 50,
            "KELP": 50,
            "SQUID_INK": 50,
            "CROISSANTS": 250,
            "JAMS": 350,
            "DJEMBES": 60,
            "PICNIC_BASKET1": 60,
            "PICNIC_BASKET2": 100,
            "VOLCANIC_ROCK": 400,
            "VOLCANIC_ROCK_VOUCHER_9500": 200,
            "VOLCANIC_ROCK_VOUCHER_9750": 200,
            "VOLCANIC_ROCK_VOUCHER_10000": 200,
            "VOLCANIC_ROCK_VOUCHER_10250": 200,
            "VOLCANIC_ROCK_VOUCHER_10500": 200,
            "MAGNIFICENT_MACARONS": 75
        }
        
        # Trading parameters
        self.max_orders = 2000
        self.window_short = 5
        self.window_long = 20
        self.resin_mean = 10000
        self.min_profit = 2
        self.trade_size = 5
        self.critical_sunlight_index = 0.5  # Initial guess for CSI
        
        # List of all products
        self.products = list(self.position_limits.keys())
        
        # Picnic basket compositions
        self.basket1_components = {
            "CROISSANTS": 6,
            "JAMS": 3,
            "DJEMBES": 1
        }
        self.basket2_components = {
            "CROISSANTS": 4,
            "JAMS": 2
        }
    
    def calculate_moving_averages(self, prices: List[float]) -> tuple[float, float]:
        if len(prices) < self.window_long:
            return None, None
        short_ma = np.mean(prices[-self.window_short:])
        long_ma = np.mean(prices[-self.window_long:])
        return short_ma, long_ma
    
    def calculate_basket_arbitrage(self, state: TradingState) -> Dict[str, List[Order]]:
        orders = {}
        
        # Calculate fair value for PICNIC_BASKET1
        basket1_value = 0
        missing_components = False
        for product, quantity in self.basket1_components.items():
            if product not in state.order_depths or not state.order_depths[product].sell_orders:
                missing_components = True
                break
            best_ask = min(state.order_depths[product].sell_orders.keys())
            basket1_value += best_ask * quantity
        
        # Calculate fair value for PICNIC_BASKET2
        basket2_value = 0
        for product, quantity in self.basket2_components.items():
            if product not in state.order_depths or not state.order_depths[product].sell_orders:
                missing_components = True
                break
            best_ask = min(state.order_depths[product].sell_orders.keys())
            basket2_value += best_ask * quantity
        
        if missing_components:
            return orders
        
        # Check if baskets exist in market
        if "PICNIC_BASKET1" in state.order_depths and "PICNIC_BASKET2" in state.order_depths:
            basket1_best_bid = max(state.order_depths["PICNIC_BASKET1"].buy_orders.keys(), default=0)
            basket2_best_ask = min(state.order_depths["PICNIC_BASKET2"].sell_orders.keys(), default=float('inf'))
            
            # Arbitrage opportunity: Buy components, sell basket
            if basket1_best_bid > basket1_value + self.min_profit:
                # Sell PICNIC_BASKET1 and buy components
                pass  # Implement this logic
            
            if basket2_value > basket2_best_ask + self.min_profit:
                # Buy PICNIC_BASKET2 and sell components
                pass  # Implement this logic
        
        return orders
    
    def trade_volcanic_vouchers(self, state: TradingState, current_positions: Dict[str, int]) -> Dict[str, List[Order]]:
        orders = {}
        
        # Check if volcanic rock is traded
        if "VOLCANIC_ROCK" not in state.order_depths:
            return orders
            
        volcanic_rock_price = (max(state.order_depths["VOLCANIC_ROCK"].buy_orders.keys()) + 
                              min(state.order_depths["VOLCANIC_ROCK"].sell_orders.keys())) / 2
        
        # Trade each voucher
        for i in [9500, 9750, 10000, 10250, 10500]:
            product = f"VOLCANIC_ROCK_VOUCHER_{i}"
            if product not in state.order_depths:
                continue
                
            strike_price = i
            order_depth = state.order_depths[product]
            best_bid = max(order_depth.buy_orders.keys(), default=0)
            best_ask = min(order_depth.sell_orders.keys(), default=float('inf'))
            
            # Calculate intrinsic value
            intrinsic_value = max(0, volcanic_rock_price - strike_price)
            
            # Trading logic
            current_pos = current_positions.get(product, 0)
            pos_limit = self.position_limits[product]
            
            # Buy if ask price is below intrinsic value
            if best_ask < intrinsic_value - self.min_profit and current_pos < pos_limit:
                buy_vol = min(pos_limit - current_pos, -order_depth.sell_orders[best_ask])
                if buy_vol > 0:
                    orders[product] = [Order(product, best_ask, buy_vol)]
            
            # Sell if bid price is above intrinsic value
            elif best_bid > intrinsic_value + self.min_profit and current_pos > -pos_limit:
                sell_vol = min(pos_limit + current_pos, order_depth.buy_orders[best_bid])
                if sell_vol > 0:
                    orders[product] = [Order(product, best_bid, -sell_vol)]
        
        return orders
    
    def trade_macaron_based_on_sunlight(self, state: TradingState, current_positions: Dict[str, int]) -> Dict[str, List[Order]]:
        orders = {}
        
        if "MAGNIFICENT_MACARONS" not in state.order_depths:
            return orders
            
        # Get sunlight index from observations
        sunlight_index = getattr(state.observations, "SUNLIGHT_INDEX", 1.0)
        
        order_depth = state.order_depths["MAGNIFICENT_MACARONS"]
        best_bid = max(order_depth.buy_orders.keys(), default=0)
        best_ask = min(order_depth.sell_orders.keys(), default=float('inf'))
        current_pos = current_positions.get("MAGNIFICENT_MACARONS", 0)
        pos_limit = self.position_limits["MAGNIFICENT_MACARONS"]
        
        # Adjust strategy based on sunlight index
        if sunlight_index < self.critical_sunlight_index:
            # Expect prices to rise - buy aggressively
            if current_pos < pos_limit:
                buy_vol = min(pos_limit - current_pos, self.trade_size, -order_depth.sell_orders[best_ask])
                if buy_vol > 0:
                    orders["MAGNIFICENT_MACARONS"] = [Order("MAGNIFICENT_MACARONS", best_ask, buy_vol)]
        else:
            # Market normal - mean reversion strategy
            mid_price = (best_bid + best_ask) / 2
            if mid_price < self.resin_mean - self.min_profit and current_pos < pos_limit:
                buy_vol = min(pos_limit - current_pos, self.trade_size, -order_depth.sell_orders[best_ask])
                if buy_vol > 0:
                    orders["MAGNIFICENT_MACARONS"] = [Order("MAGNIFICENT_MACARONS", best_ask, buy_vol)]
            elif mid_price > self.resin_mean + self.min_profit and current_pos > -pos_limit:
                sell_vol = min(pos_limit + current_pos, self.trade_size, order_depth.buy_orders[best_bid])
                if sell_vol > 0:
                    orders["MAGNIFICENT_MACARONS"] = [Order("MAGNIFICENT_MACARONS", best_bid, -sell_vol)]
        
        return orders
    
    def run(self, state: TradingState) -> tuple[Dict[str, List[Order]], int, str]:
        result = {}
        conversions = 0
        
        # Load state
        if state.traderData:
            trader_data = json.loads(state.traderData)
            prices = trader_data["prices"]
            total_orders = trader_data["total_orders"]
            avg_prices = trader_data["avg_prices"]
        else:
            prices = {p: [] for p in self.products}
            total_orders = 0
            avg_prices = {p: {"buy": 0, "sell": 0} for p in self.products}
        
        # Get current positions (default to 0 if missing)
        current_positions = {p: state.position.get(p, 0) for p in self.products}
        
        # Update price history
        for product in self.products:
            if product in state.order_depths:
                order_depth = state.order_depths[product]
                if order_depth.buy_orders and order_depth.sell_orders:
                    best_bid = max(order_depth.buy_orders.keys())
                    best_ask = min(order_depth.sell_orders.keys())
                    mid_price = (best_bid + best_ask) / 2
                    prices[product].append(mid_price)
        
        # Execute trading strategies
        if total_orders < self.max_orders:
            # 1. Basket arbitrage
            basket_orders = self.calculate_basket_arbitrage(state)
            for product, orders in basket_orders.items():
                if product not in result:
                    result[product] = []
                result[product].extend(orders)
                total_orders += len(orders)
        
            # 2. Volcanic rock vouchers
            if total_orders < self.max_orders:
                voucher_orders = self.trade_volcanic_vouchers(state, current_positions)
                for product, orders in voucher_orders.items():
                    if product not in result:
                        result[product] = []
                    result[product].extend(orders)
                    total_orders += len(orders)
            
            # 3. Macaron trading based on sunlight
            if total_orders < self.max_orders:
                macaron_orders = self.trade_macaron_based_on_sunlight(state, current_positions)
                for product, orders in macaron_orders.items():
                    if product not in result:
                        result[product] = []
                    result[product].extend(orders)
                    total_orders += len(orders)
            
            # 4. Original strategies for RAINFOREST_RESIN and KELP
            for product in ["RAINFOREST_RESIN", "KELP"]:
                if total_orders >= self.max_orders or product not in state.order_depths:
                    continue
                    
                order_depth = state.order_depths[product]
                current_pos = current_positions[product]
                orders = []
                
                best_bid = max(order_depth.buy_orders.keys())
                best_ask = min(order_depth.sell_orders.keys())
                bid_vol = order_depth.buy_orders[best_bid]
                ask_vol = -order_depth.sell_orders[best_ask]
                
                room_to_buy = self.position_limits[product] - current_pos
                room_to_sell = self.position_limits[product] + current_pos
                
                remaining_orders = self.max_orders - total_orders
                
                # KELP: Frequent shorting
                if product == "KELP":
                    short_ma, long_ma = self.calculate_moving_averages(prices[product])
                    if short_ma is not None and long_ma is not None:
                        if short_ma < long_ma and room_to_sell >= self.trade_size:
                            sell_vol = min(self.trade_size, bid_vol, room_to_sell, remaining_orders)
                            if sell_vol > 0:
                                orders.append(Order(product, best_bid, -sell_vol))
                                total_orders += 1
                                avg_prices[product]["sell"] = (avg_prices[product]["sell"] * abs(current_pos) + best_bid * sell_vol) / (abs(current_pos) + sell_vol) if current_pos - sell_vol < 0 else best_bid
                                print(f"SELL {product} {sell_vol}x at {best_bid}")
                        
                        if current_pos < 0 and best_ask <= avg_prices[product]["sell"] - self.min_profit:
                            buy_vol = min(self.trade_size, -current_pos, ask_vol, remaining_orders)
                            if buy_vol > 0:
                                orders.append(Order(product, best_ask, buy_vol))
                                total_orders += 1
                                avg_prices[product]["sell"] = 0 if current_pos + buy_vol == 0 else avg_prices[product]["sell"]
                                print(f"UNWIND BUY {product} {buy_vol}x at {best_ask}")
                
                # RAINFOREST_RESIN: Frequent mean-reversion
                elif product == "RAINFOREST_RESIN":
                    if best_ask <= self.resin_mean - self.min_profit and room_to_buy >= self.trade_size:
                        buy_vol = min(self.trade_size, ask_vol, room_to_buy, remaining_orders)
                        if buy_vol > 0:
                            orders.append(Order(product, best_ask, buy_vol))
                            total_orders += 1
                            avg_prices[product]["buy"] = (avg_prices[product]["buy"] * current_pos + best_ask * buy_vol) / (current_pos + buy_vol) if current_pos + buy_vol != 0 else best_ask
                            print(f"BUY {product} {buy_vol}x at {best_ask}")
                    
                    if best_bid >= self.resin_mean + self.min_profit and room_to_sell >= self.trade_size:
                        sell_vol = min(self.trade_size, bid_vol, room_to_sell, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["buy"] = 0 if current_pos - sell_vol == 0 else avg_prices[product]["buy"]
                            print(f"SELL {product} {sell_vol}x at {best_bid}")
                    
                    if current_pos > 0 and best_bid >= avg_prices[product]["buy"] + self.min_profit:
                        sell_vol = min(self.trade_size, current_pos, bid_vol, remaining_orders)
                        if sell_vol > 0:
                            orders.append(Order(product, best_bid, -sell_vol))
                            total_orders += 1
                            avg_prices[product]["buy"] = 0 if current_pos - sell_vol == 0 else avg_prices[product]["buy"]
                            print(f"UNWIND SELL {product} {sell_vol}x at {best_bid}")
                
                if orders:
                    result[product] = orders
        
        # Save state
        trader_data = {
            "prices": prices,
            "total_orders": total_orders,
            "avg_prices": avg_prices,
            "critical_sunlight_index": self.critical_sunlight_index
        }
        trader_data_str = json.dumps(trader_data)
        
        return result, conversions, trader_data_str