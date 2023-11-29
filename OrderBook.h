#include "Order.h"
#include "Stock.h"
#include <string>
#include <queue>
#include <vector>
#include <map>

class OrderBook {
public:
    OrderBook();

    // Methods for adding orders
    void addPendingOrder(Order& order);

    // Method for displaying the order book
    void displayOrderBook();
    void findOrderinBook(Order& order);
	Order* findOrderInBookByOrderId(int orderId);
    std::queue<Order> sortByPrice();
    Order* findLowestSell();
    Order* findHighestBuy();

	void limitBuy(std::string ticker, std::string companyName, double price, double amount, int userId);
	void limitSell(std::string ticker, std::string companyName, double price, double amount, int userId);
	void marketBuy(std::string ticker, std::string companyName, double price, double amount, int userId);
	void marketSell(std::string ticker, std::string companyName, double price, double amount, int userId);

	void editOrder(int id, std::string ticker, std::string companyName, double price, double amount, int userId, bool bCancel);



private:
    std::queue<Order> pendingOrders; 
	std::map<int, Order*> pendingOrdersMap; 
    std::vector<Order> executed;

    // Helper method for executing trades
    void executeTrades();

    struct CompareLimitSellPrice {
        bool operator()(const Order* a, const Order* b) const {
            return a->getPrice() > b->getPrice();
        }
    };

    struct CompareLimitBuyPrice {
        bool operator()(const Order* a, const Order* b) const {
            return a->getPrice() < b->getPrice();
        }
    };

    std::priority_queue<Order*, std::vector<Order*>, CompareLimitSellPrice> sellPriorityQueue;
    std::priority_queue<Order*, std::vector<Order*>, CompareLimitBuyPrice> buyPriorityQueue;
};