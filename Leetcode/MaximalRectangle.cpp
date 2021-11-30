#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

/*
 * https://leetcode.com/problems/maximal-rectangle/
 * */
class MaximalRectangle {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int ans = 0;
        int lenA = (int) matrix.size(), lenB;

        if (!lenA) return ans;
        lenB = (int) matrix[0].size();

        vvi mr(lenA, vi(lenB, 0));
        vvi maxRect(lenA, vi(lenB, 0));
        for (int i = 0; i < lenA; i += 1) {
            mr[i][0] = matrix[i][0] == '1' ? 1 : 0;
            for (int j = 0; j < lenB; j += 1) {
                if (j > 0 && matrix[i][j] == '1') mr[i][j] = mr[i][j - 1] + 1;
            }
        }

        maxRect = mr;
        for (int i = 1; i < lenA; i += 1) {
            if (maxRect[i][0]) maxRect[i][0] += maxRect[i - 1][0];
            ans = max(ans, maxRect[i][0]);
        }
        for (int i = 0; i < lenB; i+= 1) {
            ans = max(ans, maxRect[0][i]);
        }
        for (int i = 1; i < lenA; i += 1) {
            for (int j = 1; j < lenB; j += 1) {
                if (mr[i][j] != 0) {
                    int maxR = 0;
                    if (mr[i - 1][j] != 0) {
                        int minRowS = mr[i][j];
                        int k = i;
                        while (k - 1 >= 0 && mr[k - 1][j] != 0) {
                            minRowS = min(minRowS, mr[k - 1][j]);
                            k -= 1;
                            maxR = max(maxR, minRowS * (i - k + 1));
                        }
                    } else maxR = mr[i][j];
                    maxRect[i][j] = max(mr[i][j], maxR);
                    ans = max(ans, maxRect[i][j]);
                }
            }
        }
        return ans;
    }

    void work() {
//        vvc matrix = {{'0', '0', '0', '1', '0', '0', '1'},
//                      {'0', '0', '0', '0', '1', '1', '1'},
//                      {'1', '1', '1', '1', '1', '1', '1'},
//                      {'0', '0', '0', '1', '1', '1', '1'}};
//        vvc matrix = {{'1', '0', '1', '0', '0'},
//                      {'1', '0', '1', '1', '1'},
//                      {'1', '1', '1', '1', '1'},
//                      {'1', '0', '0', '1', '0'}};
//        vvc matrix = {};
//        vvc matrix = {{'1'}};
//        vvc matrix = {{'0'},{'0'}};
        vvc matrix = {{'1', '0'},{'1', '0'}};
//        vvc matrix = {{'0', '1', '1'},
//                      {'1', '1', '1'}};
        int res = maximalRectangle(matrix);
        cout << res;
    }
};