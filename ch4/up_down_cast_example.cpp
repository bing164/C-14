//
// Created by bing on 2023/10/12.
//

#include <iostream>

#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int a = 5, b = 0;
    CALL_WITH_MAX(++a, b);
    std::cout << a << std::endl;
    CALL_WITH_MAX(++a, b +10);
    std::cout << a << std::endl;
    return 0;
}
