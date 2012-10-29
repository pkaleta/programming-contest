#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

class Order {
    public:
        double price;
        int quantity;

        Order() {}

        Order(double price, int quantity) {
            this->price = price;
            this->quantity = quantity;
        }

        bool operator == (const Order& order) const {
            return this->price == order.price;
        }
};

class BuyOrder : public Order {
    public:
        BuyOrder() {}
        BuyOrder(double price, int quantity) : Order(price, quantity) { }

        bool operator < (const Order& order) const {
            return this->price < order.price;
        }

        bool operator > (const Order& order) const {
            return this->price > order.price;
        }
};

class SellOrder : public Order {
    public:
        SellOrder() {}
        SellOrder(double price, int quantity) : Order(price, quantity) { }

        bool operator < (const Order& order) const {
            return this->price > order.price;
        }

        bool operator > (const Order& order) const {
            return this->price < order.price;
        }
};

class Orders {
    public:
        int vol;
        double cp;
        priority_queue<BuyOrder> buys;
        priority_queue<SellOrder> sells;

        Orders() : vol(0), cp(0.0) {}

        void add(char type, int quantity, double price) {
            if (type == 'S') {
                SellOrder order = SellOrder(price, quantity);
                if (!buys.empty() && order.price <= buys.top().price) {
                    BuyOrder buyOrder;
                    while (!buys.empty() && order.price <= buys.top().price && order.quantity > 0) {
                        buyOrder = buys.top();
                        if (buyOrder.quantity < order.quantity) {
                            vol += buyOrder.quantity;
                            order.quantity -= buyOrder.quantity;
                            cp = buyOrder.price;
                            //TODO: erase
                            buys.pop();
                        } else {
                            vol += order.quantity;
                            cp = buyOrder.price;
                            buyOrder.quantity -= order.quantity;
                            buys.pop();
                            if (buyOrder.quantity) {
                                buys.push(buyOrder);
                            }
                            order.quantity = 0;
                            break;
                        }
                    }
                    if (order.quantity > 0) {
                        if (sells.top().price == order.price) {
                            SellOrder o = sells.top();
                            sells.pop();
                            o.quantity += order.quantity;
                            sells.push(o);
                        } else {
                            sells.push(order);
                        }
                    }
                } else {
                    if (sells.top().price == order.price) {
                        SellOrder o = sells.top();
                        sells.pop();
                        o.quantity += order.quantity;
                        sells.push(o);
                    } else {
                        sells.push(order);
                    }
                }
            } else {
                BuyOrder order = BuyOrder(price, quantity);
                if (!sells.empty() && order.price >= sells.top().price) {
                    SellOrder sellOrder;
                    while (!sells.empty() && order.price >= sells.top().price && order.quantity > 0) {
                        sellOrder = sells.top();
                        if (sellOrder.quantity < order.quantity) {
                            vol += sellOrder.quantity;
                            cp = sellOrder.price;
                            order.quantity -= sellOrder.quantity;
                            sells.pop();
                        } else {
                            vol += order.quantity;
                            cp = sellOrder.price;
                            sellOrder.quantity -= order.quantity;
                            sells.pop();
                            if (sellOrder.quantity) {
                                sells.push(sellOrder);
                            }
                            order.quantity = 0;
                            break;
                        }
                    }
                    if (order.quantity > 0) {
                        if (buys.top().price == order.price) {
                            BuyOrder o = buys.top();
                            buys.pop();
                            o.quantity += order.quantity;
                            buys.push(o);
                        } else {
                            buys.push(order);
                        }
                    }
                } else {
                    if (buys.top().price == order.price) {
                        BuyOrder o = buys.top();
                        buys.pop();
                        o.quantity += order.quantity;
                        buys.push(o);
                    } else {
                        buys.push(order);
                    }
                }
            }
        }
};

Orders* orders[256];

int main() {
    int N, L;
    double C;
    char symbol, type;
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%c %c %d %lf\n", &symbol, &type, &L, &C);
        if (!orders[symbol]) {
            orders[symbol] = new Orders();
        }
        orders[symbol]->add(type, L, C);
    }
    int count = 0;
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (orders[c] && orders[c]->vol > 0) {
            ++count;
        }
    }
    printf("%d\n", count);
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (orders[c] && orders[c]->vol > 0) {
            printf("%c %d %1.2lf\n", c, orders[c]->vol, orders[c]->cp);
        }
    }
    return 0;
}
