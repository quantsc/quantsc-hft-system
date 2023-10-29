#include "Order.h"
#include "Stock.h"
#include <queue>
#include <vector>

class OrderBook {
public:
    OrderBook();

    // Methods for adding orders
    void addPendingOrder(Order& order);

    // Method for displaying the order book
    void displayOrderBook();
    void findOrderinBook(Order& order);

private:
    std::queue<Order> pendingOrders;
    std::vector<Order> executed;

    // Helper method for executing trades
    void executeTrades();
};