from datamodel import OrderDepth, TradingState, Order
from typing import Dict, List
import json
import numpy as np
class Trader:
    def __init__(self):
        self.position_limits = {"RAINFOREST_RESIN": 50, "KELP": 50}
        self.max_orders = 2000
        self.window_short = 5
        self.window_long = 20
        self.resin_mean = 10000
        self.min_profit = 2
        self.trade_size = 5
        self.products = ["RAINFOREST_RESIN", "KELP"]
    
    def calculate_moving_averages(self, prices: List[float]) -> tuple[float, float]:
        if len(prices) < self.window_long:
            return None, None
        short_ma = np.mean(prices[-self.window_short:])
        long_ma = np.mean(prices[-self.window_long:])
        return short_ma, long_ma
    
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
        
        # Fix: Ensure all products have a position, default to 0 if missing
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
        
        # Trading logic
        for product in self.products:
            if product not in state.order_depths or total_orders >= self.max_orders:
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
            
            # Arbitrage
            if best_bid > best_ask and room_to_buy >= self.trade_size:
                arb_vol = min(self.trade_size, ask_vol, room_to_buy, remaining_orders)
                if arb_vol > 0:
                    orders.append(Order(product, best_ask, arb_vol))
                    total_orders += 1
                    avg_prices[product]["buy"] = (avg_prices[product]["buy"] * current_pos + best_ask * arb_vol) / (current_pos + arb_vol) if current_pos + arb_vol != 0 else best_ask
                    print(f"ARBITRAGE BUY {product} {arb_vol}x at {best_ask}")
            
            if orders:
                result[product] = orders
        
        # Save state
        trader_data = {
            "prices": prices,
            "total_orders": total_orders,
            "avg_prices": avg_prices
        }
        trader_data_str = json.dumps(trader_data)
        
        return result, conversions, trader_data_str
    




