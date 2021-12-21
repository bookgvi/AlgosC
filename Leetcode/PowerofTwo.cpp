#include <bits/stdc++.h>

using namespace std;

class PowerofTwo {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (!(n & (n - 1))) return true;
        return false;
    }

    void work() {
        int n = 16;
        bool res = isPowerOfTwo(n);
    }
};