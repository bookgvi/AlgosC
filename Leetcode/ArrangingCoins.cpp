#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int arrangeCoins(int n) {
        vector<int> dp;
        dp.push_back(1);
        n -= dp[0];
        int k = 1;
        while (n > dp[dp.size() - 1]) {
            dp.push_back(dp[k - 1] + 1);
            n -= dp[k];
            k += 1;
        }
        return dp.size();
    }
};

//int main() {
//    Solution s;
//    int res = s.arrangeCoins((1 << 31) - 1);
//}