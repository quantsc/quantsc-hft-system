#pragma once
#include <string>
#include "Stock.h"

enum OrderType { Buy, Sell, LimitBuy, LimitSell };

class Order {
    private:
        int orderId;
        int userId;
        std::string ticker;
        OrderType orderType;
        int price;
        int volume;
        int timestamp;

    public:
        // Constructor
        Order(
            int orderId,
            int userId,
            bool isBuy,
            int price,
			Stock stock,
            int volume,
            int timestamp
        );

        // Accessors
        int getOrderId();
        int getUserId();
        std::string getTicker();
        bool getIsBuy();
        int getPrice();
        int getVolume();
        int getTimestamp();

        // Mutators
        void setOrderId(int orderId);
        void setUserId(int userId);
        void setTicker(std::string ticker);
        void setIsBuy(bool isBuy);
        void setPrice(int price);
        void setVolume(int volume);
        void setTimestamp(int timestamp);      
};