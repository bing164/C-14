//
// Created by bing on 2023/10/9.
//

#include <iostream>
#include <cmath>

using namespace std;

template <typename F, typename T>
T inline fin_diff(F f, const T& x, const T& h) {
    return (f(x + h) - f(x)) / h;
}

int main(int argc, char** argv) {
    double a, b, c;
    // 无捕获
    a = fin_diff([](double x) {return sin(2.5 * x);}, 1., 0.001);
    std::cout << "a = " << a << std::endl;

    // 按值捕获
    double phi = 2.5, xi = 0.2;
    b = fin_diff([phi](double x) {return sin(phi * x) + cos(x);}, 1., 0.001);
    c = fin_diff([phi, xi](double x) {return sin(phi * x) + cos(x) * xi;}, 1., 0.001);
    std::cout << "b = " << b << " c = " << c << std::endl;
    printf("按值捕获 phi = %f, xi = %f", phi, xi);

    // 按引用捕获
    double d;
    b = fin_diff([&phi](double x) {phi += 1.0; return sin(phi * x) + cos(x);}, 1., 0.001);
    std::cout << "d = " << d << std::endl;
    printf("按引用捕获 phi = %f, xi = %f", phi, xi);

    return 0;
}
