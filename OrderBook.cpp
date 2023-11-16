#include "OrderBook.h"
#include <queue>
#include <vector>
#include <chrono>
#include <map>

using namespace std;

OrderBook::OrderBook() {

}

void OrderBook::addPendingOrder(Order& order) {
    pendingOrders.push(order);
	pendingOrdersMap.insert{(order.orderId, &order)};
    executeTrades();
}

void OrderBook::executeTrades() {
    while (!pendingOrders.empty()) {
		if (pendingOrders.front().cancelled) {
			pendingOrdersMap.erase(pendingOrders.front().orderId);
			pendingOrders.pop();
		}
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
			pendingOrdersMap.erase(pendingOrders.front().orderId);
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
			pendingOrdersMap.erase(pendingOrders.front().orderId);
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

void OrderBook::findOrderInBookByOrderId(int orderId) {
    
}


uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void OrderBook::limitBuy(string ticker, string companyName, double price, double amount, int userId) {
	Order order(pendingOrders.size(), userId, ticker, companyName, Order::IsBuy::LimitBuy, price, amount, timeSinceEpochMillisec());
	this->addPendingOrder(order);
}

void OrderBook::limitSell(string ticker, string companyName, double price, double amount, int userId) {
	Order order(pendingOrders.size(), 0, userId, ticker, companyName, Order::IsBuy::LimitSell, price, amount, timeSinceEpochMillisec());
	this->addPendingOrder(order);
}

void OrderBook::marketBuy(string ticker, string companyName, double price, double amount, int userId) {
	Order order(pendingOrders.size(), 0, userId, ticker, companyName, Order::IsBuy::Buy, price, amount, timeSinceEpochMillisec());
	this->addPendingOrder(order);
}

void OrderBook::marketSell(string ticker, string companyName, double price, double amount, int userId) {
	Order order(pendingOrders.size(), 0, userId, ticker, companyName, Order::IsBuy::Sell, price, amount, timeSinceEpochMillisec());
	this->addPendingOrder(order);
}

void OrderBook::editOrder(int id, string ticker, string companyName, double price, double amount, int userId, bool bCancel) {
	if (pendingOrdersMap.count(id) > 0) {
		if (bCancel) {
			pendingOrdersMap[id].cancelled = true;
		}
		else {
			pendingOrdersMap[id]->setTicker(ticker);
			pendingOrdersMap[id]->companyName = companyName;
			pendingOrdersMap[id]->setPrice(price);
			pendingOrdersMap[id]->setVolume(volume);
			pendingOrdersMap[id]->setTimestamp(timeSinceEpochMillisec());
		}
	}
}

int main() {
    return 0;
}
