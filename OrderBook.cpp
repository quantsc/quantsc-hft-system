#include "OrderBook.h"
#include <queue>
#include <vector>

using namespace std;

OrderBook::OrderBook() {

}

void OrderBook::addPendingOrder(Order& order) {
    pendingOrders.push(order);
    executeTrades();
}

void OrderBook::executeTrades() {
    while (!pendingOrders.empty()) {
        if(!(pendingOrders.front().getIsLimit()) || (pendingOrders.front().getIsLimit() && pendingOrders.front().getPrice()==2/*price to buy/sell at specified by isLimit order, not sure if this is should be in  order class or here*/))
        {
            if(pendingOrders.front().getIsBuy())
            {
                //actual execution to buy + error handling
            }
            else
            {
                //actual execution to sell + error handling
            }
            executed.push_back(pendingOrders.front());
            //maybe save info like time of execution?
            pendingOrders.pop();
        }
    }
}

void OrderBook::displayOrderBook() {
    for(Order order : executed)
    {
        // maybe add a print function to order so we can display nicely
    }
}

int main() {
    return 0;
}
