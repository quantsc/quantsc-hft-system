#pragma once
#include <string>
#include <map>

class Stock {
    public:
        // Constructor
        Stock(
            std::string ticker, 
            std::string companyName,
            int currentPrice,
            int shares,
            int marketCap,
            std::map<std::string, int> priceLog
        );

        // Accessors
        std::string getTicker();
        std::string getCompanyName();
        int getCurrentPrice();
        int getShares();
        int getMarketCap();
        std::map<std::string, int> getPriceLog();

        // Mutators
        void setTicker(std::string ticker);
        void setCompanyName(std::string companyName);
        void setCurrentPrice(int currentPrice);
        void setShares(int shares);
        void setMarketCap(int marketCap);
        void setPriceLog(std::string date, int price);

        // Display Methods
        void displayTicker();
        void displayCompanyName();
        void displayCurrentPrice();
        void displayShares();
        void displayMarketCap();
        void displayPriceLog();
        void displayAll();
        
    private:
        std::string ticker;
        std::string companyName;
        int currentPrice;
        int shares;
        int marketCap;
        std::map<std::string, int> priceLog;
};