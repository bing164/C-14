#include <iostream>
#include <memory>
#include <cassert>
using namespace std;

class vector {
public:
    vector() : my_size(0), data(0) {}
    vector(int size) : my_size(size), data(new double[size]) {}

    vector(const vector& that) : my_size(that.my_size), data(new double[my_size]) {
        cout << "copy " << endl;
        for (int i = 0; i < my_size; i++) {
            data[i] = that.data[i];
        }
    }

    void operator=(const vector& that) {
        assert(that.my_size == my_size);
        cout << " = fun()" << endl;
        for (int i = 0; i < my_size; i++)
            data[i] = that.data[i];
    }

    double& operator[](int i) {
        assert(i >= 0 && i < my_size);
//        cout << " []1 " << endl;
        return data[i];
    }

    double& operator[](int i) const {
        assert(i >= 0 && i < my_size);
//        cout << " []2" << endl;
        return data[i];
    }

    int size() const {
        return my_size;
    }

private:
    int my_size;
    std::unique_ptr<double[]> data;
};

std::ostream& operator<<(std::ostream& os, const vector& v) {
    os << "[";
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ",";
    }
    os << "]";
    return os;
}

double dot(const vector& v, const vector& w) {
    double s;
    for (int i = 0; i < v.size(); i++) {
        s += v[i] * w[i];
    }
    return s;
}

int main(int argc, char** argv) {
    vector v(4);
    v[0] = v[1] = 1.0; v[2] = 2.0; v[3] = -3.0;
    std::cout << v << std::endl;

    vector w(v.size());
    w = v;

    const vector z(w);
    std::cout << "z[3] is " << z[3] << '\n';

    std::cout << "w is " << w << '\n';
    v[1] = 9.;
    std::cout << "w is " << w << '\n';

    return 0;
}
