#include "Order.h"

Order::Order(
    int orderId,
    int userId,
    std::string ticker,
    std::string companyName,
    IsBuy isBuy,
    int price,
    int volume,
    int timestamp
) {
    this->orderId = orderId;
    this->userId = userId;
    this->ticker = ticker;
    this->companyName = companyName;
    this->isBuy = isBuy;
    this->price = price;
    this->volume = volume;
    this->timestamp = timestamp;
}

int Order::getOrderId() {
    return this->orderId;
}

int Order::getUserId() {
    return this->userId;
}

std::string Order::getTicker() {
    return this->ticker;
}

Order::IsBuy Order::getIsBuy() {
    return this->isBuy;
}

int Order::getPrice() {
    return this->price;
}

int Order::getVolume() {
    return this->volume;
}

int Order::getTimestamp() {
    return this->timestamp;
}

void Order::setOrderId(int orderId) {
    this->orderId = orderId;
}

void Order::setUserId(int userId) {
    this->userId = userId;
}

void Order::setTicker(std::string ticker) {
    this->ticker = ticker;
}

// to finish...


int main() {
    return 0;
}