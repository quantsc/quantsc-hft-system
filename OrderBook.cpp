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
        if(!(pendingOrders.front().getIsBuy()==Order::IsBuy::Buy) || (pendingOrders.front().getIsBuy()==Order::IsBuy::LimitBuy && pendingOrders.front().getPrice()==2/*price to buy/sell at specified by isLimit order, not sure if this is should be in  order class or here*/))
        {
            if(pendingOrders.front().getIsBuy()==Order::IsBuy::Buy)
            {
                //actual execution to buy, not limit
            }
            else
            {
                //actual execution to buy, limit
            }
            executed.push_back(pendingOrders.front());
            //maybe save info like time of execution?
            pendingOrders.pop();
        }
        if(!(pendingOrders.front().getIsBuy()==Order::IsBuy::Sell) || (pendingOrders.front().getIsBuy()==Order::IsBuy::LimitSell && pendingOrders.front().getPrice()==2/*price to buy/sell at specified by isLimit order, not sure if this is should be in  order class or here*/))
        {
            if(pendingOrders.front().getIsBuy()==Order::IsBuy::Sell)
            {
                //actual execution to sell, not limit
            }
            else
            {
                //actual execution to sell, limit
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

void OrderBook::findOrderinBook(Order& order) {
    for(Order order : executed)
    {
        // maybe add a search function
    }
}

int main() {
    return 0;
}
