#include <Stock.h>
#include <iostream>

// Constructor
Stock::Stock(
    std::string ticker, 
    std::string companyName,
    int currentPrice,
    int shares,
    int marketCap,
    std::map<std::string, int> priceLog
) {
    this->ticker = ticker;
    this->companyName = companyName;
    this->currentPrice = currentPrice;
    this->shares = shares;
    this->marketCap = marketCap;
    this->priceLog = priceLog;
}

// Accessors
std::string Stock::getTicker() {
    return this->ticker;
}

std::string Stock::getCompanyName() {
    return this->companyName;
}

int Stock::getCurrentPrice() {
    return this->currentPrice;
}

int Stock::getShares() {
    return this->shares;
}

int Stock::getMarketCap() {
    return this->marketCap;
}

std::map<std::string, int> Stock::getPriceLog() {
    return this->priceLog;
}

// Mutators
void Stock::setTicker(std::string ticker) {
    this->ticker = ticker;
}

void Stock::setCompanyName(std::string companyName) {
    this->companyName = companyName;
}

void Stock::setCurrentPrice(int currentPrice) {
    this->currentPrice = currentPrice;
}

void Stock::setShares(int shares) {
    this->shares = shares;
}

void Stock::setMarketCap(int marketCap) {
    this->marketCap = marketCap;
}

void Stock::setPriceLog(std::string date, int price) {
    this->priceLog[date] = price;
}

// Display Methods
void Stock::displayTicker() {
    std::cout << "Ticker: " << this->ticker << std::endl;
}

void Stock::displayCompanyName() {
    std::cout << "Company Name: " << this->companyName << std::endl;
}

void Stock::displayCurrentPrice() {
    std::cout << "Current Price: " << this->currentPrice << std::endl;
}

void Stock::displayShares() {
    std::cout << "Shares: " << this->shares << std::endl;
}

void Stock::displayMarketCap() {
    std::cout << "Market Cap: " << this->marketCap << std::endl;
}

void Stock::displayPriceLog() {
    std::cout << "Price Log: " << std::endl;
    for (auto const& x : this->priceLog) {
        std::cout << x.first << ": " << x.second << std::endl;
    }
}

void Stock::displayAll() {
    this->displayTicker();
    this->displayCompanyName();
    this->displayCurrentPrice();
    this->displayShares();
    this->displayMarketCap();
    this->displayPriceLog();
}