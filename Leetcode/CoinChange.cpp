#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

/*
 * https://leetcode.com/problems/coin-change/
 * */
class CoinChange {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) return -1;
        vi dp, first, ans;
        int inf = INT_MAX / 10 * 9;
        dp.push_back(0);
        first.push_back(0);
        for (int i = 1; i <= amount; i += 1) {
            dp.push_back(inf);
            first.push_back(0);
            for (auto coin: coins)
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                    first[i] = coin;
                }
        }
        int k = amount;
        while(k != 0 && first[k] != 0) {
            ans.push_back(first[k]);
            k -= first[k];
        }
        return dp.back() != inf ? dp.back() : -1;
    }

    void work() {
        vi coins = {2, 1};
        int amount = 11;
        int res = coinChange(coins, amount);
        cout << "res";
    }
};