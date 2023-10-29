//
// Created by bing on 2023/10/29.
//

#include <iostream>

/// 绝不能在构造和析构过程中调用virtual函数

class Transaction {
public:
    Transaction() {
        init();
    }

    virtual void logTransaction() const = 0;

private:
    void init() {
        logTransaction();
    }
};

//Transaction::Transaction() {
//    logTransaction();
//}

class BuyTransaction : public Transaction {
public:
    virtual void logTransaction() const {
        std::cout << "buy " << std::endl;
    }
};

class SellTransaction : public Transaction {
public:
    virtual void logTransaction() const {
        std::cout << "sell " << std::endl;
    }
};

int main(int argc, char** argv) {
    BuyTransaction b;
    return 0;
}

