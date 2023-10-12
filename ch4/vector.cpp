#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void out(vector<int> &v) {
    for (int a : v) {
        cout << a << endl;
    }
    return;
}

int main() {
    vector<int> v = {3, 4, 7, 9};
    auto it = std::find(v.begin(), v.end(), 4);
    std::cout << "After " << *it << " comes " << *(it + 1) << std::endl;

    v.insert(it+1, 5);
//    out(v);

    v.erase(v.begin() + 1);
    cout << v.capacity() << endl;
    v.shrink_to_fit();
    cout << endl;
    cout << v.capacity() << endl;
    out(v);
    return 0;
}
