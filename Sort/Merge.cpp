#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class Merge {
private:

    static vi sort(vi &arr) {
        for (int i = 1, len = (int) arr.size(); i < len; i <<= 1)
            for (int j = 0; j < len - i; j += i << 1)
                merge(j, i + j, min(len, j + (i << 1)), arr);
        return arr;
    }

    static void merge(int l, int mid, int r, vi &arr) {
        int it1 = 0, it2 = 0;
        vi merge(r - l, 0);
        while (l + it1 < mid && mid + it2 < r) {
            if (arr[l + it1] < arr[mid + it2]) {
                merge[it1 + it2] = arr[l + it1];
                it1 += 1;
            } else {
                merge[it1 + it2] = arr[mid + it2];
                it2 += 1;
            }
        }
        while (l + it1 < mid) {
            merge[it1 + it2] = arr[l + it1];
            it1 += 1;
        }
        while (mid + it2 < r) {
            merge[it1 + it2] = arr[mid + it2];
            it2 += 1;
        }
        for (int i = 0; i < it1 + it2; i += 1)
            arr[l + i] = merge[i];
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