#include <bits/stdc++.h>

using namespace std;

class LCS {
public:
    int maxProduct(vector<int> &nums) {
        int maxV = nums[nums.size() - 1];
        vector<int> maxD(nums.size(), nums[nums.size() - 1]);
        for (auto i = nums.size() - 1; i > 0; i -= 1) {
            int prod = nums[i];
            for (auto j = i - 1; j >= 0; j -= 1) {
                prod *= nums[j];
                maxD[i] = max(nums[j], max(prod, maxD[i]));
            }
        }
        for (auto i = 0; i != maxD.size(); i += 1)
            maxV = max(maxD[i], maxV);
        return maxV;
    }

    void work() {
//        vector<int> nums = {2,-5,-2,-4,3};
//        vector<int> nums = {-3, 0, 1, -2};
        vector<int> nums = {2,3,-2,4};
//        vector<int> nums = {-4, -3};
//        vector<int> nums = {3,-1,4};
        maxProduct(nums);
    }
};
