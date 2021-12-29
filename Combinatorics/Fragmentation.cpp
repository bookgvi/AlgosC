#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class Fragmentation {
private:
    vi nextFragment(vi &arr, int num) {
        int n = (int) arr.size(), i = 0;
        for (i = 0; i < n; i += 1) {
            if (i < n - 1 && arr[i] == 1) break;
        }
        if (i == n) {
            for (i = 0; i < n - 2; i += 1)
                if (arr[i] == arr[i + 1]) break;
        }
        int incElt = arr[i] + 1;
        int sum = incElt;
        for (int j = 0; j < i; j += 1)
            sum += arr[j];
        int newN = num - sum + i + 1; // i + 1 - количество уже увеличенных, включая в текущий цикл, элементов; +1 - из-за 0-индексации
        vi newArr(newN, 1);
        for (int j = 0; j <= i; j += 1)
            newArr[j] = j == i ? incElt : arr[j];

        return newArr;
    }

    void display(vi &arr) {
        for (auto elt : arr)
            cout << elt << " ";
        cout << "\n";
    }

public:
    void work() {
        vi start = {1, 1, 1, 1, 1, 1,1,1};
        int num = 0;
        for (auto elt: start) num += elt;
        display(start);
        while (start.size() > 1) {
            start = nextFragment(start, num);
            display(start);
        }
    }
};
