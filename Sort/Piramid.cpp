#include <bits/stdc++.h>

using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef vector<int> vi;

void displayArr(vector<int> arr);

void siftDown(int v, vi &arr);

vi buildHeap(vector<int> &arr);

vi sortP(vector<int> arr);

//int main() {
//    int ints[] = {1, 15, 13, 12, 3, 5, 7, 8, 9, 0};
//    vector<int> arr(ints, ints + 10);
//    displayArr(arr);
//    displayArr(arr);
//
//    vi res = sortP(arr);
//    displayArr(res);
//}

vi sortP(vi arr) {
    int len = arr.size();
    vi sorted;
    buildHeap(arr);
    for (int i = 0; i < len; i += 1) {
        sorted.push_back(arr[0]);
        arr[0] = INT_MAX;
        siftDown(0, arr);
    }
    return sorted;
}

vi buildHeap(vi &arr) {
    for (int i = arr.size(); i >= 0; i -= 1)
        siftDown(i, arr);
    return arr;
}

void siftDown(int v, vi &arr) {
    int len = arr.size(), half = len >> 1;
    while(v < half) {
        int l = (v << 1) + 1;
        int r = l + 1;
        int t = r < len && arr[r] < arr[l] ? r : l;
        if (arr[v] <= arr[t]) break;
        swap(arr[v], arr[t]);
        v = t;
    }
}

void displayArr(vi arr) {
    for (int i = 0, len = arr.size(); i < len; i += 1) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}