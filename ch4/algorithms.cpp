//
// Created by bing on 2023/10/11.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    vector<int> v = {3, 4, 7, 9, 2, 5, 7, 8, 3, 4, 3, 9};
    std::sort(v.begin(), v.end(), [](int a, int b) {return a < b;});
    for (int a : v) {
        cout << a << endl;
    }
    return 0;
}

