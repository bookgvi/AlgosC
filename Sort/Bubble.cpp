#include <bits/stdc++.h>
#include "RCG.cpp"

using namespace std;
typedef vector<int> vi;

class Bubble {
private:
    static vi sort(vi arr) {
        for (int i = 0, len = (int) arr.size(); i < len; i += 1)
            for (int j = 0; j < len - 1; j += 1)
                if (arr[j] > arr[j + 1]) swap(arr[j + 1], arr[j]);
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
        display(arr);
        sort(arr);
        display(arr);
    }
};