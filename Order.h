#pragma once
#include <string>

class Order {
    private:
        int orderId;
        int userId;
        std::string ticker;
        bool isBuy;
        int price;
        int volume;
        int timestamp;

    public:
        // Constructor
        Order(
            int orderId,
            int userId,
            std::string ticker,
            std::string companyName,
            bool isBuy,
            int price,
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