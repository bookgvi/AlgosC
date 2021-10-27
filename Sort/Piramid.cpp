#include <bits/stdc++.h>

typedef unsigned long ul;
typedef long long ll;
using namespace std;

void displayArr(vector<int> arr);
vector<int> siftDown(int v, vector<int> & arr);
vector<int> buildHeap(vector<int> & arr);
void sort(vector<int> arr);

int mmain() {
    int ints[] = {1, 15, 13, 12, 3, 5, 7, 8, 9, 0};
    vector<int> arr(ints, ints + 10);
    displayArr(arr);
    displayArr(arr);

    sort(arr);
    displayArr(arr);
}

void sort(vector<int> arr) {
    arr = buildHeap(arr);
    vector<int> sorted;
    for (int i = 0, len = arr.size(); i < len; i += 1) {
        sorted[i] = arr[0];
        arr[0] = INFINITY;
        siftDown(0, arr);
    }
}

vector<int> buildHeap(vector<int> & arr) {
    for (int i = arr.size(); i >= 0; i -= 1)
        siftDown(i, arr);
    return arr;
}

vector<int>  siftDown(int v, vector<int> &arr) {
    ul len = arr.size(), half = len >> 1;
    while (v < half) {
        int l = (v << 1) + 1;
        int r = l + 1;
        int t = r < len && arr[r] < arr[l] ? r : l;
        if (arr[v] <= arr[t]) break;
        swap(arr[v], arr[t]);
        v = t;
    }
    return arr;
}

void displayArr(vector<int> arr) {
    for (int i = 0; i < arr.size(); i += 1)
        cout << arr[i] << " ";
    cout << "\n";
}