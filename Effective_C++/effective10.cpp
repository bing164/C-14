//
// Created by bing on 2023/10/30.
//

#include <iostream>

/// operator= 返回一个reference to *this实现连锁赋值，即 x = y = z = 15;
class Widget {
public:
    Widget(int w) : value(w) {}

    Widget& operator= (const Widget& A) {  // 返回类型是个引用
        value = A.value;
        return *this;
    }

    void out() {
        std::cout << value << std::endl;
    }
private:
    int value;
};

int main(int argc, char** argv) {
    Widget w1(1), w2(2), w3(3);
    w1 = w2 = w3;
    w1.out();
    w2.out();
    w3.out();
    return 0;
}

