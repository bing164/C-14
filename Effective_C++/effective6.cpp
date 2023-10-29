//
// Created by bing on 2023/10/29.
//

#include <iostream>

class Uncopyable {
protected:
    Uncopyable() {}

    ~Uncopyable() {}

private:
    Uncopyable(const Uncopyable& A) {}
    Uncopyable operator= (const Uncopyable& B) {}
};

class HomeForSale : private Uncopyable {
public:
    HomeForSale() {}
//private:
//    HomeForSale(const HomeForSale& A) {}
//
//    HomeForSale& operator= (const HomeForSale& B) {}
};

int main(int argc, char** argv) {
    HomeForSale h1;
    HomeForSale h2;
    /// 下述两行代码不能实现的方法：
    /// 1 将HomeForSale类中的拷贝构造函数和=函数设为private
    /// 2 重新写个Uncopyable类，然后使用HomeForSale继承Uncopyable类
//    HomeForSale h3(h1);
//    h1 = h2;
    return 0;
}

