#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi sort(vi arr, int len) {
    for (int i = 0; i < len ; i += 1)
        for (int j = 0; j < len - 1; j += 1)
            if (arr[j] - arr[j + 1] > 0) swap(arr[j], arr[j + 1]);
    return arr;
}

int main() {
    vi arr = {2, 3, 45, 1, 0, 5, 5, 1, 1, 34, 12, 11};
    vi sortedArr = sort(arr, arr.size());

    for (int elt : arr) cout << elt << " ";
    cout << "\n";
    for (int elt : sortedArr) cout << elt << " ";
    cout << "\n";

    return 0;
}
