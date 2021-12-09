#pragma once
using namespace std;

class RCG {
public:
    int seed;
    void _srand(int x) {
        seed = x;
    }

    int _rand(){
        return (((seed = seed * 214013L + 2531011L) >> 16) & 0x7fff);
    }
};