//
// Created by bing on 2023/10/9.
//

#include <iostream>
#include <cmath>

using namespace std;

double sc(double x) {
    return sin(x) + cos(x);
}

class psc_f {
public:
    psc_f(double alpha) : alpha(alpha) {}
    double operator() (double x) const {
        return sin(alpha * x) + cos(x);
    }

private:
    double alpha;
};

template <typename F, typename T>
inline T fin_diff(F f, const T& x, const T& h) {
    return (f(x + h) - f(x)) / h;
}

template <typename F, typename T>
class derivative{
public:
    derivative(const F& f, const T& h) : f(f), h(h) {}

    T operator() (const T& x) const {
        return (f(x + h) - f(x)) / h;
    }

private:
    const F& f;
    T h;
};

template <typename F, typename T>
class second_derivative {
public:
    second_derivative(const F& f, const T& h) : h(h), fp(f, h) {}
    T operator() (const T& x) const {
        return (fp(x + h) - fp(x)) / h;
    }

private:
    T h;
    derivative<F, T> fp;
};

template <typename F, typename T, unsigned N>
class nth_derivative{
    using prev_derivative = nth_derivative<F, T, N-1>;
public:
    nth_derivative(const F& f, const T& h) : h(h), fp(f, h) {}

    T operator() (const T& x) const {
        return N & 1 ? (fp(x + h) - fp(x)) / h
                     : (fp(x) - fp(x - h)) / h;
    }

private:
    T h;
    prev_derivative fp;
};

template <typename F, typename  T>
class nth_derivative<F, T, 1> : public derivative<F, T> {
    using derivative<F, T>::derivative;
};

int main(int argc, char** argv) {
    psc_f psc_o(1.0);
    std::cout << fin_diff(psc_o, 1., 0.001) << std::endl;
    std::cout << fin_diff(psc_f(2.0), 1., 0.001) << std::endl;
    std::cout << fin_diff(sc, 0., 0.001) << std::endl;

    // 求二阶导数
    // 方法1
    using d_psc_f = derivative<psc_f, double>;
    using dd_psc_f = derivative<d_psc_f, double>;

    d_psc_f d_psc_o(psc_o, 0.001);
    dd_psc_f dd_psc_o(d_psc_o, 0.001);

    std::cout << "der. of size(0) + cos(0) is " << d_psc_o(0.0) << std::endl;
    std::cout << "2nd der. of size(0) + cos(0) is " << dd_psc_o(0.0) << std::endl;

    // 方法2
    second_derivative<psc_f, double> dd_psc_2_o(psc_f(1.0), 0.001);
    cout << "2nd der. of sin(0) + cos(0) is " << dd_psc_2_o(0.0) << '\n';

    // 求n价导数
    nth_derivative<psc_f, double, 2> dd_psc_3_o(psc_f(1.0), 0.001);
    cout << "2nd der. of sin(0) + cos(0) is " << dd_psc_3_o(0.0) << '\n';

    nth_derivative<psc_f, double, 6> d6_psc_o(psc_f(1.0), 0.00001);
    cout << "6th der. of sin(0) + cos(0) is " << d6_psc_o(0.0) << '\n';

    return 0;
}

