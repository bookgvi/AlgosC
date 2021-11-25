#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Combinations {
private:
    int comb(int n, int k) {
        vvi d(n + 1, vi(n + 1));
        d[0][0] = 1;
        for (int i = 1; i <= n; i += 1) {
            d[i][0] = 1;
            d[i][i] = 1;
            for (int j = 1; j < i; j += 1)
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
        return d[n][k];
    }

    vector<vector<int>> generate(int numRows) {
        vvi d(numRows);
        d[0].push_back({1});
        for (int i = 1; i < numRows; i += 1) {
            vi col(i + 1, 1);
            d[i] = col;
            for (int j = 1; j < i; j += 1)
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
        return d;
    }
public:
    void work() {
        vvi res = generate(7);
        cout << "res" << "\n";
    }
};