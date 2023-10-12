//
// Created by bing on 2023/10/10.
//

/// this指针的使用
/// 作用：1. 避免构造器的入参与成员名相同
///      2. 用于多重串联调用
#include <iostream>

using namespace std;

class Stu {
public:
    Stu(string name, int age)  // : name(name), age(age)  这里介绍this指针，就不用列表初始化了
    {
        this->name = name;
        this->age = age;
    }

    Stu & growUp() {
        this->age++;
        return *this;
    }

    void display() {
        std::cout << name << " : " << age << endl;
    }

private:
    string name;
    int age;
};

int main(int argc, char** argv) {
    Stu s("bing", 30);
    s.display();

    s.growUp().growUp().growUp().growUp().growUp();
    s.display();
    return 0;
}

