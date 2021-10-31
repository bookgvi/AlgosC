#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class Coins {
public:
    vi solve(int n, vi coins) {
        vi values, first;
        values.push_back(0);
        first.push_back(0);
        for (int i = 1; i <= n; i += 1) {
            values.push_back(INT_MAX / 2);
            first.push_back(0);
            for (int coin : coins) {
                if ((i - coin) >= 0 && values[i - coin] + 1 < values[i]) {
                    values[i] = values[i - coin] + 1;
                    first[i] = coin;
                }
            }
        }
        return first;
    }
};

//int main() {
//    Coins coins1;
//    vi coins = {1, 22, 3, 10, 2};
//    int n = 51;
//    vi res = coins1.solve(n, coins);
//    while (n > 0) {
//        printf("%d ", res[n]);
//        n -= res[n];
//    }
//    cout << "\n";
//}
