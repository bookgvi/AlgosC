#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/maximum-subarray/
 * */
class MaximumSubArray {
public:
    int maxSubArray(vector<int>& nums) {
        int maxV = nums[0], res = nums[0];
        for (auto i = 1; i != nums.size(); i += 1) {
            maxV = max(nums[i], nums[i] + maxV);
            res = max(maxV, res);
        }
        return res;
    }

    void work() {
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        int res = maxSubArray(nums);
        cout << res;
    }
};
