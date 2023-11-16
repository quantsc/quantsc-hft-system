#include "Order.h"
#include "Stock.h"
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
	void findOrderInBookByOrderId(int orderId);

	void limitBuy(string ticker, string companyName, double price, double amount, int userId);
	void limitSell(string ticker, string companyName, double price, double amount, int userId);
	void marketBuy(string ticker, string companyName, double price, double amount, int userId);
	void marketSell(string ticker, string companyName, double price, double amount, int userId);

	void editOrder(int id, string ticker, string companyName, double price, double amount, int userId, bool bCancel);


private:
    std::queue<Order> pendingOrders; 
	std::map<int, Order*> pendingOrdersMap; 
    std::vector<Order> executed;

    // Helper method for executing trades
    void executeTrades();
};