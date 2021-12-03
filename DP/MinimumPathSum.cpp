#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/minimum-path-sum/
 * */
class MinimumPathSum {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int rowCount = (int) grid.size(), colCount = (int) grid[0].size();
        vvi cost = grid;
        for (int col = 1; col < colCount; col += 1)
            cost[0][col] += cost[0][col - 1];
        for (int row = 1; row < rowCount; row += 1)
            cost[row][0] += cost[row - 1][0];
        for (int row = 1; row < rowCount; row += 1) {
            for (int col = 1; col < colCount; col += 1) {
                cost[row][col] = min(cost[row - 1][col], cost[row][col - 1])
                                 + grid[row][col];
            }
        }

        return cost[rowCount - 1][colCount - 1];
    }

    void work() {
        vvi grid = {{1, 2, 3},
                    {4, 5, 6}};
        int res = minPathSum(grid);
        cout << res;
    }
};