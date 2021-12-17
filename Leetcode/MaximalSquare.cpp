#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/maximal-square/submissions/
 * */
class MaximalSquare {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int rowCount = (int) matrix.size(), colCount = (int) matrix[0].size(), ans = 0;
        if (rowCount == 1) {
            for (int col = 0; col < colCount; col += 1) {
                int val = matrix[0][col] == '1' ? 1 : 0;
                ans = max(val, ans);
            }
        } else {
            vvi prep(rowCount, vi(colCount, 0));
            for (int row = 0; row < rowCount; row += 1) {
                prep[row][0] = matrix[row][0] == '1' ? 1 : 0;
                for (int col = 1; col < colCount; col += 1)
                    if (matrix[row][col] == '1') {
                        prep[row][col] += 1;
                        prep[row][col] += prep[row][col - 1];
                    }
            }

            for (int col = 0; col < colCount; col += 1) {
                int val = matrix[0][col] == '1' ? 1 : 0;
                ans = max(val, ans);
            }
            for (int row = 1; row < rowCount; row += 1) {
                for (int col = 0; col < colCount; col += 1) {
                    if (prep[row][col] != 0) {
                        int mul = prep[row][col], k = row;
                        ans = max(ans, 1);
                        while (k >= 0 && prep[k][col] > 1) {
                            mul = min(mul, prep[k][col]);
                            if (row - k + 1 == mul) ans = max(mul * mul, ans);
                            k -= 1;
                        }
                    }
                }
            }
        }
        return ans;
    }

    void work() {
        vector<vector<char>> matrix = {{'0', '0', '0', '1'},
                                       {'1', '1', '0', '1'},
                                       {'1', '1', '1', '1'},
                                       {'0', '1', '1', '1'},
                                       {'0', '1', '1', '1'}};
//
//        vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
//                                       {'0', '1', '1', '1', '1'},
//                                       {'1', '1', '1', '1', '1'},
//                                       {'1', '0', '0', '1', '0'}};
        maximalSquare(matrix);
    }

};