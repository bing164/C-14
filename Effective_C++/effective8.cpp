//
// Created by bing on 2023/10/29.
//

#include <iostream>

class DBConnection {
public:
    static DBConnection create() {}

    void close() {}
};

class DBConn {
public:

    ~DBConn() {
        if (!closed) {
            try {
                db.close();
            } catch (...) {

            }
        }
    }
    void close() {
        db.close();
        closed = true;
    }



private:
    DBConnection db;
    bool closed;
};

int main(int argc, char** argv) {

    return 0;
}

