#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/arithmetic-slices/
 * */
class ArithmeticSlices {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int len = (int) nums.size(), res = 0;
        if (len < 3) return 0;
        vector<vector<int>> dp;
        vector<int> diff;
        int delta = nums[0] - nums[1];
        diff.push_back(delta);
        nums.push_back(INT_MAX / 4 * 3);
        for (int i = 1; i < len; i += 1) {
            if (delta == (nums[i] - nums[i + 1])) {
                diff.push_back(delta);
            } else {
                delta = nums[i] - nums[i + 1];
                if(diff.size() >= 2) dp.push_back(diff);
                diff = {};
                diff.push_back(delta);
            }
        }
        for (auto& arr : dp) {
            len = (int) arr.size();
            int count = len + 1;
            for(int i = 3; i <= count; i += 1)
                res += count - i + 1;
        }
        return res;
    }

    void work() {
//        vector<int> nums = {1, 3, 5, 7, 9, 11};
//        vector<int> nums = {7,7,7,7};
//        vector<int> nums = {10,1,2,3,4, 5, 7, 9, 11,0};
        vector<int> nums = {1,2,3,4, 5, 7, 9, 11};
        int res = numberOfArithmeticSlices(nums);
    }
};
