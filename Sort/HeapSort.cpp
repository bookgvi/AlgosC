#include <bits/stdc++.h>

using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef vector<int> vi;

class HeapSort {
private:
    static void siftDown(int v, vi &arr) {
        int len = (int) arr.size(), half = len >> 1;
        while (v < half) {
            int l = (v << 1) + 1;
            int r = l + 1;
            int t = r < len && arr[r] < arr[l] ? r : l;
            if (arr[v] <= arr[t]) break;
            swap(arr[v], arr[t]);
            v = t;
        }
    }

    static void siftUp(int v, vi &arr) {
        while (v > 0 && arr[v] < arr[v >> 1]) {
            swap(arr[v], arr[v >> 1]);
            v >>= 1;
        }
    }

    static vi build(vi arr) {
        for (int i = (int) arr.size(); i >= 0; i -= 1)
            siftDown(i, arr);
        return arr;
    }

    static vi sort(vi arr) {
        int len = (int) arr.size();
        vi sorted(len, 0);
        arr = build(arr);
        for (int i = 0; i < len; i += 1) {
            sorted[i] = arr[0];
            arr[0] = INT_MAX;
            siftDown(0, arr);
        }
        return sorted;
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
        cout << "Heap sort\n";
        display(arr);
        arr = sort(arr);
        display(arr);
    }

};