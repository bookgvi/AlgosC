#include <bits/stdc++.h>

using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef vector<int> vi;

class HeapSort {
private:
    vi siftUp(int v, vi heap) {
        while (v > 0 && heap[v] < heap[v >> 1]) {
            swap(heap[v], heap[v >> 1]);
            v >>= 1;
        }
        return heap;
    }

    vi siftDown(int v, vi &heap) {
        int len = (int) heap.size(), half = len >> 1;
        while (v < half) {
            int l = (v << 1) + 1;
            int r = l + 1;
            int t = r < len && heap[r] < heap[l] ? r : l;
            if (heap[v] <= heap[t]) break;
            swap(heap[v], heap[t]);
            v = t;
        }
        return heap;
    }

    vi buildHeap(vi &origArr) {
        vi arr = origArr;
        for (auto i = (int) arr.size() - 1; i >= 0; i -= 1)
            arr = siftDown(i, arr);
        return arr;
    }

    vi sort(vi &arr) {
        vi heap = buildHeap(arr);
        vi sorted;
        for (int i = 0; i < (int) arr.size(); i += 1) {
            sorted.push_back(heap[0]);
            heap[0] = INT_MAX;
            siftDown(0, heap);
        }
        return sorted;
    }

    void display(vi &arr) {
        for (auto elt: arr)
            cout << elt << " ";
        cout << "\n";
    }

public:
    void work() {
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