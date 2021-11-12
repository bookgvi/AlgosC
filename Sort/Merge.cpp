#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void merge(int l, int mid, int r, int * ptrArr) {
    int it1 = 0, it2 = 0;
    int merge[r - l];
    while (l + it1 < mid && mid + it2 < r) {
        if (*(ptrArr + l + it1) < *(ptrArr + mid + it2)) {
            merge[it1 + it2] = *(ptrArr + l + it1);
            it1 += 1;
        } else {
            merge[it1 + it2] = *(ptrArr + mid + it2);
            it2 += 1;
        }
    }
    while (l + it1 < mid) {
        merge[it1 + it2] = *(ptrArr + l + it1);
        it1 += 1;
    }
    while (mid + it2 < r) {
        merge[it1 + it2] = *(ptrArr + mid + it2);
        it2 += 1;
    }
    for (int i = 0; i < it1 + it2; i += 1)
        *(ptrArr + l + i) = merge[i];
}

vi sortM(vi arr, int len) {
    for (int i = 1; i < len; i <<= 1) {
        for (int j = 0; j < len - i; j += (i << 1)) {
            merge(j, j + i, min(len, j + (i << 1)), &arr[0]);
        }
    }
    return arr;
}

//int _Mmain() {
//    vi arr = {2, 3, 45, 1, 0, 5, 5, 1, 1, 34, 12, 11};
//    vi sortedArr = sortM(arr, arr.size());
//
//    for (int elt : arr) cout << elt << " ";
//    cout << "\n";
//    for (int elt : sortedArr) cout << elt << " ";
//    cout << "\n";
//}
