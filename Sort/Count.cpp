#include <bits/stdc++.h>
#include "RCG.cpp"

using namespace std;
typedef vector<int> vi;

class CountSort {
private:
    static vi sort(vi &arr) {
        int len = (int) arr.size(), b = 8, dw = 4;
        vi t(len, 0);
        for (int p = 0; p < dw; p += 1) {
            vi count(1 << b, 0);
            for (int elt : arr)
                count[((elt ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)] += 1;
            for (int i = 1; i < 1 << b; i += 1)
                count[i] += count[i - 1];
            for(int i = len - 1; i >= 0; i -= 1)
                t[--count[((arr[i] ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)]] = arr[i];
            for (int i = 0; i < len; i += 1)
                arr[i] = t[i];
        }
        return arr;
    }

    static void display(vi &arr) {
        for (auto elt : arr)
            cout << elt << " ";
        cout << "\n";
    }

public:
    static void work() {
        RCG rcg;
        vi arr;
        rcg._srand(123);
        for (int i = 0; i < 10; i += 1)
            arr.push_back(rcg._rand());
        cout << "Count sort\n";
        display(arr);
        sort(arr);
        display(arr);
    }
};