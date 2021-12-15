#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class Insert {
private:

    static vi sort(vi &arr) {
        for (int i = 0, len = (int) arr.size(); i < len; i += 1)
            for (int j = i; j > 0 && arr[j - 1] > arr[j]; j -= 1)
                swap(arr[j - 1], arr[j]);
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
        cout << "Insert sort\n";
        display(arr);
        sort(arr);
        display(arr);
    }

};