#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vvi dp(m + 1, vi(n + 1, 1));
        for (int i = 2; i <= m; i += 1)
            for (int j = 2; j <= n; j += 1)
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        return dp[m][n];
    }
};