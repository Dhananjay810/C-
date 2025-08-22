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
            "VOLCANIC_ROCK_VOUCHER_10500": 200, "MAGNIFICENT_MACARONS": 75
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
        self.squid_ink_z_threshold = 2.0
        self.mean_window = 5
        self.trade_qty = 3
        self.basket_qty = 2
        self.macaron_qty = 2  # Smaller for luxury product
        self.macaron_conversion_limit = 10
        self.basket_components = {
            "PICNIC_BASKET1": {"CROISSANTS": 6, "JAMS": 3, "DJEMBES": 1},
            "PICNIC_BASKET2": {"CROISSANTS": 4, "JAMS": 2}
        }

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
                max_window = max(self.squid_ink_window, self.mean_window)
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

    def calculate_voucher_value(self, voucher: str, rock_price: float) -> float:
        if rock_price is None:
            return None
        strike = self.voucher_details[voucher]["strike"]
        days_left = self.voucher_details[voucher]["days_left"]
        intrinsic_value = max(0, rock_price - strike)
        time_factor = days_left / 7
        return intrinsic_value * time_factor

    def trade_vouchers(self, state: TradingState) -> Dict[str, List[Order]]:
        result = {}
        for voucher in self.voucher_details:
            if voucher not in state.order_depths:
                continue
            order_depth = state.order_depths[voucher]
            current_position = self.positions[voucher]
            position_limit = self.position_limits[voucher]
            orders = []
            rock_price = self.fair_values.get("VOLCANIC_ROCK", None)
            voucher_value = self.calculate_voucher_value(voucher, rock_price)
            if voucher_value is None:
                continue
            buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
            sell_orders = sorted(order_depth.sell_orders.items())
            best_bid = buy_orders[0][0] if buy_orders else None
            best_ask = sell_orders[0][0] if sell_orders else None
            best_bid_qty = buy_orders[0][1] if buy_orders else 0
            best_ask_qty = sell_orders[0][1] if sell_orders else 0
            spread = 2
            our_bid = max(1, int(voucher_value - spread))
            our_ask = int(voucher_value + spread)
            if current_position < position_limit and best_ask and our_bid >= best_ask:
                qty_to_buy = min(best_ask_qty, position_limit - current_position)
                if qty_to_buy > 0:
                    orders.append(Order(voucher, best_ask, qty_to_buy))
            elif current_position < position_limit:
                orders.append(Order(voucher, our_bid, position_limit - current_position))
            if current_position > -position_limit and best_bid and our_ask <= best_bid:
                qty_to_sell = min(best_bid_qty, current_position + position_limit)
                if qty_to_sell > 0:
                    orders.append(Order(voucher, best_bid, -qty_to_sell))
            elif current_position > -position_limit:
                orders.append(Order(voucher, our_ask, -(position_limit + current_position)))
            if orders:
                result[voucher] = orders
        return result

    def trade_volcanic_rock(self, state: TradingState) -> List[Order]:
        product = "VOLCANIC_ROCK"
        orders = []
        if product not in state.order_depths:
            return orders
        order_depth = state.order_depths[product]
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        fair_value = self.fair_values.get(product, None)
        if fair_value is None:
            return orders
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        best_bid = buy_orders[0][0] if buy_orders else None
        best_ask = sell_orders[0][0] if sell_orders else None
        best_bid_qty = buy_orders[0][1] if buy_orders else 0
        best_ask_qty = sell_orders[0][1] if sell_orders else 0
        if current_position < position_limit and best_ask:
            qty_to_buy = min(best_ask_qty, position_limit - current_position)
            if qty_to_buy > 0:
                orders.append(Order(product, best_ask, qty_to_buy))
        if current_position > -position_limit and best_bid:
            qty_to_sell = min(best_bid_qty, current_position + position_limit)
            if qty_to_sell > 0:
                orders.append(Order(product, best_bid, -qty_to_sell))
        return orders

    def trade_squid_ink(self, state: TradingState) -> List[Order]:
        product = "SQUID_INK"
        orders = []
        if product not in state.order_depths or len(self.price_history[product]) < self.squid_ink_window:
            return orders
        prices = np.array(self.price_history[product][-self.squid_ink_window:])
        mean_price = np.mean(prices)
        std_price = np.std(prices) if np.std(prices) > 0 else 1e-10
        current_mid_price = prices[-1]
        z_score = (current_mid_price - mean_price) / std_price
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        best_bid = buy_orders[0][0] if buy_orders else None
        best_ask = sell_orders[0][0] if sell_orders else None
        best_bid_qty = buy_orders[0][1] if buy_orders else 0
        best_ask_qty = sell_orders[0][1] if sell_orders else 0
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        if (z_score > self.squid_ink_z_threshold and current_position > -position_limit and
                best_bid and best_bid_qty >= 5):
            qty = min(self.trade_qty, best_bid_qty, position_limit + current_position)
            if qty > 0:
                orders.append(Order(product, best_bid, -qty))
        elif (z_score < -self.squid_ink_z_threshold and current_position < position_limit and
              best_ask and best_ask_qty >= 5):
            qty = min(self.trade_qty, best_ask_qty, position_limit - current_position)
            if qty > 0:
                orders.append(Order(product, best_ask, qty))
        return orders

    def trade_rainforest_resin(self, state: TradingState) -> List[Order]:
        product = "RAINFOREST_RESIN"
        orders = []
        if product not in state.order_depths or len(self.price_history[product]) < self.mean_window:
            return orders
        mean_price = np.mean(self.price_history[product][-self.mean_window:])
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        best_bid = buy_orders[0][0] if buy_orders else None
        best_ask = sell_orders[0][0] if sell_orders else None
        best_bid_qty = buy_orders[0][1] if buy_orders else 0
        best_ask_qty = sell_orders[0][1] if sell_orders else 0
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        spread = best_ask - best_bid if best_ask and best_bid else float('inf')
        if (best_ask and best_ask < 0.995 * mean_price and current_position < position_limit and
                spread <= 4 and best_ask_qty >= 5):
            qty = min(self.trade_qty, best_ask_qty, position_limit - current_position)
            if qty > 0:
                orders.append(Order(product, best_ask, qty))
        if (best_bid and best_bid > 1.005 * mean_price and current_position > -position_limit and
                spread <= 4 and best_bid_qty >= 5):
            qty = min(self.trade_qty, best_bid_qty, position_limit + current_position)
            if qty > 0:
                orders.append(Order(product, best_bid, -qty))
        return orders

    def trade_kelp(self, state: TradingState) -> List[Order]:
        product = "KELP"
        orders = []
        if product not in state.order_depths or len(self.price_history[product]) < self.mean_window:
            return orders
        mean_price = np.mean(self.price_history[product][-self.mean_window:])
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        best_bid = buy_orders[0][0] if buy_orders else None
        best_ask = sell_orders[0][0] if sell_orders else None
        best_bid_qty = buy_orders[0][1] if buy_orders else 0
        best_ask_qty = sell_orders[0][1] if sell_orders else 0
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        spread = best_ask - best_bid if best_ask and best_bid else float('inf')
        if (best_ask and best_ask < 0.995 * mean_price and current_position < position_limit and
                spread <= 2 and best_ask_qty >= 5):
            qty = min(self.trade_qty, best_ask_qty, position_limit - current_position)
            if qty > 0:
                orders.append(Order(product, best_ask, qty))
        if (best_bid and best_bid > 1.005 * mean_price and current_position > -position_limit and
                spread <= 2 and best_bid_qty >= 5):
            qty = min(self.trade_qty, best_bid_qty, position_limit + current_position)
            if qty > 0:
                orders.append(Order(product, best_bid, -qty))
        return orders

    def trade_magnificent_macarons(self, state: TradingState) -> List[Order]:
        product = "MAGNIFICENT_MACARONS"
        orders = []
        if product not in state.order_depths or len(self.price_history[product]) < self.mean_window:
            return orders
        mean_price = np.mean(self.price_history[product][-self.mean_window:])
        order_depth = state.order_depths[product]
        buy_orders = sorted(order_depth.buy_orders.items(), reverse=True)
        sell_orders = sorted(order_depth.sell_orders.items())
        best_bid = buy_orders[0][0] if buy_orders else None
        best_ask = sell_orders[0][0] if sell_orders else None
        best_bid_qty = buy_orders[0][1] if buy_orders else 0
        best_ask_qty = sell_orders[0][1] if sell_orders else 0
        current_position = self.positions[product]
        position_limit = self.position_limits[product]
        spread = best_ask - best_bid if best_ask and best_bid else float('inf')
        if (best_ask and best_ask < 0.995 * mean_price and current_position < position_limit and
                spread <= 3 and best_ask_qty >= 5):
            qty = min(self.macaron_qty, best_ask_qty, position_limit - current_position)
            if qty > 0:
                orders.append(Order(product, best_ask, qty))
        if (best_bid and best_bid > 1.005 * mean_price and current_position > -position_limit and
                spread <= 3 and best_bid_qty >= 5):
            qty = min(self.macaron_qty, best_bid_qty, position_limit + current_position)
            if qty > 0:
                orders.append(Order(product, best_bid, -qty))
        return orders

    def trade_baskets(self, state: TradingState) -> Dict[str, List[Order]]:
        result = {}
        for basket in ["PICNIC_BASKET1", "PICNIC_BASKET2"]:
            if basket not in state.order_depths:
                continue
            orders = []
            components = self.basket_components[basket]
            basket_mid = self.fair_values.get(basket, None)
            if basket_mid is None:
                continue
            component_value = 0
            all_components_valid = True
            for component, qty in components.items():
                comp_mid = self.fair_values.get(component, None)
                if comp_mid is None:
                    all_components_valid = False
                    break
                component_value += qty * comp_mid
            if not all_components_valid:
                continue
            basket_position = self.positions[basket]
            basket_limit = self.position_limits[basket]
            basket_depth = state.order_depths[basket]
            basket_buy_orders = sorted(basket_depth.buy_orders.items(), reverse=True)
            basket_sell_orders = sorted(basket_depth.sell_orders.items())
            basket_best_bid = basket_buy_orders[0][0] if basket_buy_orders else None
            basket_best_ask = basket_sell_orders[0][0] if basket_sell_orders else None
            basket_bid_qty = basket_buy_orders[0][1] if basket_buy_orders else 0
            basket_ask_qty = basket_sell_orders[0][1] if basket_sell_orders else 0
            if (basket_best_ask and basket_best_ask < 0.98 * component_value and
                    basket_position < basket_limit and basket_ask_qty >= 5):
                qty = min(self.basket_qty, basket_limit - basket_position, basket_ask_qty)
                can_trade = True
                for component, comp_qty in components.items():
                    comp_position = self.positions[component]
                    comp_limit = self.position_limits[component]
                    if comp_position - qty * comp_qty < -comp_limit * 0.8:
                        can_trade = False
                        break
                    comp_depth = state.order_depths.get(component, OrderDepth())
                    comp_buy_orders = sorted(comp_depth.buy_orders.items(), reverse=True)
                    if not comp_buy_orders or comp_buy_orders[0][1] < 5:
                        can_trade = False
                        break
                if can_trade and qty > 0:
                    orders.append(Order(basket, basket_best_ask, qty))
                    for component, comp_qty in components.items():
                        comp_depth = state.order_depths[component]
                        comp_buy_orders = sorted(comp_depth.buy_orders.items(), reverse=True)
                        comp_price = comp_buy_orders[0][0]
                        comp_qty_to_sell = qty * comp_qty
                        orders.append(Order(component, comp_price, -comp_qty_to_sell))
            elif (basket_best_bid and basket_best_bid > 1.02 * component_value and
                  basket_position > -basket_limit and basket_bid_qty >= 5):
                qty = min(self.basket_qty, basket_limit + basket_position, basket_bid_qty)
                can_trade = True
                for component, comp_qty in components.items():
                    comp_position = self.positions[component]
                    comp_limit = self.position_limits[component]
                    if comp_position + qty * comp_qty > comp_limit * 0.8:
                        can_trade = False
                        break
                    comp_depth = state.order_depths.get(component, OrderDepth())
                    comp_sell_orders = sorted(comp_depth.sell_orders.items())
                    if not comp_sell_orders or comp_sell_orders[0][1] < 5:
                        can_trade = False
                        break
                if can_trade and qty > 0:
                    orders.append(Order(basket, basket_best_bid, -qty))
                    for component, comp_qty in components.items():
                        comp_depth = state.order_depths[component]
                        comp_sell_orders = sorted(comp_depth.sell_orders.items())
                        comp_price = comp_sell_orders[0][0]
                        comp_qty_to_buy = qty * comp_qty
                        orders.append(Order(component, comp_price, comp_qty_to_buy))
            if orders:
                result[basket] = orders
                for component in components:
                    comp_orders = [o for o in orders if o.product == component]
                    if comp_orders:
                        result[component] = comp_orders
        return result

    def run(self, state: TradingState) -> (Dict[str, List[Order]], int, str):
        self.round += 1
        result = {}
        conversions = 0
        trader_data = ""

        self.update_positions(state)
        self.update_price_history(state)
        for product in state.order_depths:
            self.update_fair_value(product, state)

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

        macaron_orders = self.trade_magnificent_macarons(state)
        if macaron_orders:
            result["MAGNIFICENT_MACARONS"] = macaron_orders

        # Handle conversions for MAGNIFICENT_MACARONS
        macaron_position = self.positions["MAGNIFICENT_MACARONS"]
        position_limit = self.position_limits["MAGNIFICENT_MACARONS"]
        if abs(macaron_position) > position_limit * 0.7:  # 70% of position limit
            conversion_qty = min(self.macaron_conversion_limit, abs(macaron_position))
            conversions = -conversion_qty if macaron_position > 0 else conversion_qty

        basket_orders = self.trade_baskets(state)
        result.update(basket_orders)

        for voucher in self.voucher_details:
            self.voucher_details[voucher]["days_left"] = max(0, 7 - self.round + 1)

        return result, conversions, trader_data