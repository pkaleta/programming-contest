#include <cstdio>
#include <algorithm>

using namespace std;

template <class T>
class ListItem {
    public:
        T order;
        ListItem* next;
};

template <class T>
class List {
    public:
        ListItem<T>* head;
        void add(T& order) {
            if (!head) {
                head = new ListItem<T>();
                head->order = order;
                head->next = NULL;
            } else {
                ListItem<T>* item = new ListItem<T>();
                item->order = order;

                if (order == head->order) {
                    head->order.quantity += order.quantity;
                } else if (order > head->order) {
                    item->next = head;
                    head = item;
                } else {
                    ListItem<T>* prev = head;
                    ListItem<T>* cur = head->next;

                    while(cur && order < cur->order) {
                        prev = cur;
                        cur = cur->next;
                    }
                    if (prev->order == order) {
                        prev->order.quantity += order.quantity;
                    } else {
                        item->next = cur;
                        prev->next = item;
                    }
                }
            }
        }

        bool empty() {
            return !head;
        }
};

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
        List<BuyOrder> buys;
        List<SellOrder> sells;

        Orders() : vol(0), cp(0.0) {}

        void print() {
            printf("sprzedaj: \n");
            ListItem<SellOrder>* i;
            for (i = sells.head; i; i = i->next) {
                printf("******* %d %lf\n", i->order.price, i->order.quantity);
            }
            printf("kup: \n");
            ListItem<BuyOrder>* j;
            for (j = buys.head; j; j = j->next) {
                printf("******* %d %lf\n", j->order.price, j->order.quantity);
            }
            printf("\n\n");
        }

        void add(char type, int quantity, double price) {
            if (type == 'S') {
                SellOrder order = SellOrder(price, quantity);
                if (!buys.empty() && order.price <= buys.head->order.price) {
                    ListItem<BuyOrder>* buyOrder = buys.head;
                    while (buyOrder && order.price <= buyOrder->order.price && order.quantity > 0) {
                        if (buyOrder->order.quantity < order.quantity) {
                            vol += buyOrder->order.quantity;
                            order.quantity -= buyOrder->order.quantity;
                            cp = buyOrder->order.price;
                            //TODO: erase
                            buyOrder = buys.head = buys.head->next;
                        } else {
                            vol += order.quantity;
                            cp = buyOrder->order.price;
                            buyOrder->order.quantity -= order.quantity;
                            if (buyOrder->order.quantity == 0) {
                                buyOrder = buys.head = buys.head->next;
                            }
                            order.quantity = 0;
                        }
                    }
                    if (order.quantity > 0) {
                        sells.add(order);
                    }
                } else {
                    sells.add(order);
                }
            } else {
                BuyOrder order = BuyOrder(price, quantity);
                if (!sells.empty() && order.price >= sells.head->order.price) {
                    ListItem<SellOrder>* sellOrder = sells.head;
                    while (sellOrder && order.price >= sellOrder->order.price && order.quantity > 0) {
                        if (sellOrder->order.quantity < order.quantity) {
                            vol += sellOrder->order.quantity;
                            cp = sellOrder->order.price;
                            order.quantity -= sellOrder->order.quantity;
                            sellOrder = sells.head = sells.head->next;
                        } else {
                            vol += order.quantity;
                            cp = sellOrder->order.price;
                            sellOrder->order.quantity -= order.quantity;
                            if (sellOrder->order.quantity == 0) {
                                sellOrder = sells.head = sells.head->next;
                            }
                            order.quantity = 0;
                        }
                    }
                    if (order.quantity > 0) {
                        buys.add(order);
                    }
                } else {
                    buys.add(order);
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
