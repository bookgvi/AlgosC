#include <bits/stdc++.h>
#include "RCG.cpp"

using namespace std;
typedef vector<int> vi;

class Select {
private:
    static vi sort(vi arr) {
        for (int i = 0, len = (int) arr.size(); i < len; i += 1)
            for (int j = i + 1; j < len; j += 1)
                if (arr[i] - arr[j] > 0) swap(arr[i], arr[j]);
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
        cout << "Select sort\n";
        display(arr);
        sort(arr);
        display(arr);
    }

};