
/// 类中构造函数使用

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class A {
public:
    A() {}
    A(int d, char* p) : data(d) {
        pd = new char[strlen(p) + 1];
        strcpy(pd, p);
    }

    ~A() {
        delete [] pd;
    }

    A(const A& another) {
        std::cout << "copy " << std::endl;
        data = another.data;
        pd = new char[strlen(another.pd) + 1];
        strcpy(pd, another.pd);
    }

    void operator= (const A& another) {
        std::cout << "operator = " << std::endl;
        data = another.data + 1;
        pd = new char[strlen(another.pd) + 1];
        strcpy(pd, another.pd);
    }

    void dis() {
        std::cout << data << std::endl;
        std::cout << pd << endl;
    }

private:
    int data;
    char* pd;
};

int main() {
    // 1 构造函数
    A a(20, "china");
    a.dis();

    // 2 拷贝构造函数
    A b(a);
    b.dis();

    // 3 一般构造函数 + 重载=
    A c;
    c = b;
    c.dis();

    // 4 拷贝构造函数
    A d = a;
    d.dis();
    return 0;
}
