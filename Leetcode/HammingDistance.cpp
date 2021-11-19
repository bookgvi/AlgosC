#include <bits/stdc++.h>
using namespace std;

class HammingDistance {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int setDiff = x ^ y;
        for (int i = 0; i < 32; i += 1) {
            if (setDiff & (1 << i)) count += 1;
        }
        return count;
    }
};