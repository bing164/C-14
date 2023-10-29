//
// Created by bing on 2023/10/29.
//

#include <iostream>

/// 为多态基类声明virtual析构函数

class TimeKeeper {
public:
    TimeKeeper() {
        std::cout << "construct 1" << std::endl;
    }
    virtual ~TimeKeeper() {
        std::cout << "delete 1" << std::endl;
    }
};

class AtomicClock : public TimeKeeper { // 原子钟

};

class WaterClock : public TimeKeeper { // 水钟

};

class WristWatch : public TimeKeeper { // 腕表

};

TimeKeeper* getTimeKeeper() {
    TimeKeeper* time = new TimeKeeper();
    return time;
}

int main(int argc, char** argv) {
    TimeKeeper* ptk = getTimeKeeper();
    delete ptk;
    return 0;
}

