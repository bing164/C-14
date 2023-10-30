//
// Created by bing on 2023/10/30.
//

#include <iostream>

/// 在operator中处理“自我赋值”,自我赋值发生在对象被赋值给自己时

class Bitmap {
public:
    Bitmap() {
        std::cout << "Bitmap construct " << std::endl;
    }

    Bitmap(const Bitmap& A) {
        std::cout << "Bitmap copy " << std::endl;
    }
};

class Widget {
public:
    Widget& operator= (const Widget& A) {
        std::cout << "Widget operator= " << std::endl;
        Bitmap* pOrig = pb;
        pb = new Bitmap(*A.pb);
        delete pOrig;
        return *this;
    }

private:
    Bitmap* pb;
};


int main(int argc, char** argv) {
    Widget w;
    w = w;
    return 0;
}

