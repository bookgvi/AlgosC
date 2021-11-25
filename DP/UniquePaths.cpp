#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class UniquePaths {
public:
    int uniquePaths(int m, int n) {
        vvi dp(m + 1, vi(n + 1, 1));
        for (int i = 2; i <= m; i += 1)
            for (int j = 2; j <= n; j += 1)
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        return dp[m][n];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int rowSize = (int) obstacleGrid.size(), colSize = (int) obstacleGrid[0].size();
        if (obstacleGrid[0][0]) return 0;
        obstacleGrid[0][0] = 1;
        for (int row = 1; row < rowSize; row += 1)
            obstacleGrid[row][0] = (!obstacleGrid[row][0] && obstacleGrid[row - 1][0]) ? 1 : 0;
        for (int col = 1; col < colSize; col += 1)
            obstacleGrid[0][col] = (!obstacleGrid[0][col] && obstacleGrid[0][col - 1]) ? 1 : 0;
        for (int row = 1; row < rowSize; row += 1)
            for (int col = 1; col < colSize; col += 1)
                obstacleGrid[row][col] = !obstacleGrid[row][col] ? obstacleGrid[row - 1][col] + obstacleGrid[row][col - 1] : 0;
        return obstacleGrid[rowSize - 1][colSize - 1];
    }

    void work() {
//        vvi obstacleGrid = {{0, 0, 0},
//                            {1, 1, 1},
//                            {0, 0, 0}};
//        vvi obstacleGrid = {{0,0},{1,1},{0,0}};
        vvi obstacleGrid = {{0,0, 0},{0,1,0},{0,0,0}};
//        vvi obstacleGrid = {{0,1, 0},{0,1,0},{0,1,0}};
//        vvi obstacleGrid = {{0, 1, 0},
//                            {1, 0, 0},
//                            {0, 0, 0}};
        int t = uniquePaths(3, 3);
        int res = uniquePathsWithObstacles(obstacleGrid);
        cout << "re";
    }
};