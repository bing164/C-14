//
// Created by bing on 2023/10/29.
//

#include <iostream>

/// 绝不能在构造和析构过程中调用virtual函数

class Transaction {
public:
    explicit Transaction(const std::string& logInfo);

    void logTransaction(const std::string& logInfo) const {
        std::cout << "Transaction logTransaction" << std::endl;
    }

};

Transaction::Transaction(const std::string &logInfo) {
    std::cout << "construct Transaction " << logInfo << std::endl;
    logTransaction(logInfo);
}

class BuyTransaction : public Transaction {
public:
    BuyTransaction() : Transaction(createLogString()) {
        std::cout << "construct BuyTransaction" << std::endl;
    }

private:
    static std::string createLogString();
};

std::string BuyTransaction::createLogString() {
    std::cout << "BuyTransaction createLogString" << std::endl;
    return "123";
}

class SellTransaction : public Transaction {
public:
    virtual void logTransaction() const {
        std::cout << "sell " << std::endl;
    }
};

int main(int argc, char** argv) {
//    const std::string& str = "1030";
    BuyTransaction b;
    return 0;
}

