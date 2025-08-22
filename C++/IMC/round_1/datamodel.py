from typing import Dict, List

class Order:
    def __init__(self, product: str, price: int, quantity: int):
        self.product = product
        self.price = price
        self.quantity = quantity

class OrderDepth:
    def __init__(self):
        self.buy_orders: Dict[int, int] = {}  # price -> volume
        self.sell_orders: Dict[int, int] = {}

class TradingState:
    def __init__(self):
        self.traderData = ""
        self.position: Dict[str, int] = {}
        self.order_depths: Dict[str, OrderDepth] = {}
