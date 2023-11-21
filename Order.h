#pragma once
#include <string>

class Order {
    private:
        int orderId;
        int userId;
        std::string ticker;
        std::string companyName;
        //enum IsBuy{Buy, Sell, LimitBuy, LimitSell};
        int price;
        int volume;
        int timestamp;
		

    public:
        enum class IsBuy{Buy, Sell, LimitBuy, LimitSell};
		bool cancelled;

        // Constructor
        Order(
            int orderId,
            int userId,
            std::string ticker,
            std::string companyName,
            IsBuy isBuy,
            int price,
            int volume,
            int timestamp
        );

        // Accessors
        int getOrderId();
        int getUserId();
        std::string getTicker();
        IsBuy getIsBuy();
        int getPrice() const;
        int getVolume();
        int getTimestamp();

        // Mutators
        void setOrderId(int orderId);
        void setUserId(int userId);
        void setTicker(std::string ticker);
        void setIsBuy(IsBuy isBuy);
        void setPrice(int price);
        void setVolume(int volume);
        void setTimestamp(int timestamp);     
  
};