#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class CountSort {
private:
    vi sort(vi arr) {
        int len = (int) arr.size(), b = 8, dw = 4;
        vi t(len, 0);
        for(int p = 0; p < dw; p += 1) {
            vi count(1 << b, 0);
            for (int elt : arr)
                count[((elt ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)] += 1;
            for (int i = 1; i < 1 << b; i += 1)
                count[i] += count[i - 1];
            for (int i = len - 1; i >= 0; i -= 1)
                t[--count[((arr[i] ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)]] = arr[i];
            for (int i = 0; i < len; i += 1)
                arr[i] = t[i];
        }
        return arr;
    }

public:
    void work() {
        vi nums = {1, 13, 43, 1, 23, 4, 6, 5,10};
        vi sorted = sort(nums);
        cout << "res";
    }
};