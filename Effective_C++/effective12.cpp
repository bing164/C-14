//
// Created by bing on 2023/10/30.
//

#include <iostream>

/// 复制对象时不要忘记其每一个成分

void logCall(const std::string& funcName) {
    std::cout << funcName << std::endl;
    return;
}

class Date {
public:
    Date() {
        logCall("Date constructor");
    }
    Date(const Date& A) {
        logCall("Date copy constructor");
    }
};

class Customer {
public:
    Customer() : name("123") {
        logCall("Customer copy constructor");
    }

    Customer(const Customer& A) : name(A.name), lastTransaction(A.lastTransaction) {
        logCall("Customer copy constructor");
    }

    Customer& operator= (const Customer& B) {
        logCall("Customer copy assignment operator");
        name = B.name;
        lastTransaction = B.lastTransaction; /// 还得重新写Date中的拷贝构造函数和=重载
        return *this;
    }
    void out() {
        std::cout << "name = " << name << std::endl;
    }

private:
    std::string name;
    Date lastTransaction;
};

class PriorityCustomer : public Customer {
public:
    PriorityCustomer(int n) : priority(n) {}
    PriorityCustomer(const PriorityCustomer& A) : priority(A.priority), Customer(A) {
        logCall("PriorityCustomer copy constructor");
    }
    PriorityCustomer& operator= (const PriorityCustomer& B) {
        logCall("PriorityCustomer copy assignment operator");
        Customer::operator=(B);
        priority = B.priority;
        return *this;
    }

    void out() {
        std::cout << "priority = " << priority << std::endl;
    }
private:
    int priority;
};

int main(int argc, char** argv) {
    PriorityCustomer p(1);
    PriorityCustomer q(p);  /// Customer q(p);
    q.out();
    return 0;
}
