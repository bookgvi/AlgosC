#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi sortI(vi arr, int len) {
    for (int i = 0; i < len ; i += 1)
        for (int j = i; j > 0 && arr[j - 1] - arr[j] > 0; j -= 1)
            swap(arr[j], arr[j - 1]);
    return arr;
}

//int _Imain() {
//    vi arr = {2, 3, 45, 1, 0, 5, 5, 1, 1, 34, 12, 11, 666};
//    vi sortedArr = sortI(arr, arr.size());
//
//    for (int elt : arr) cout << elt << " ";
//    cout << "\n";
//    for (int elt : sortedArr) cout << elt << " ";
//    cout << "\n";
//
//    return 0;
//}
