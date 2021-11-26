#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/trapping-rain-water/
 * */
class TrappingRainWater {
public:
    int trap(vector<int> &height) {
        int len = (int) height.size(), res = 0;
        vector<int> leftHeight(len, 0), rightHeight(len, 0);
        leftHeight[0] = height[0];
        rightHeight[len - 1] = height[len - 1];
        for (int i = 1; i < len; i += 1)
            leftHeight[i] = max(leftHeight[i - 1], height[i]);
        for (int i = len - 2; i >= 0; i -= 1)
            rightHeight[i] = max(rightHeight[i + 1], height[i]);
        for (int i = 0; i < len; i += 1)
            res += min(leftHeight[i], rightHeight[i]) - height[i];
        return res;
    }

    void work() {
        vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        int res = trap(height);
        cout << res;
    }
};

