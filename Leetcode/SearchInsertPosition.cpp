#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/search-insert-position/submissions/
 * */
class SearchInsertPosition {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = binSearch(nums, target);
        return res < 0 ? -(res + 1) : res;
    }

    int binSearch(vector<int> &nums, int target) {
        int len = (int) nums.size(), l = 0, r = len - 1;
        while(r - l >= 0) {
            int mid = (r + l) >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -(l + 1);
    }

    void work() {
        vector<int> nums = {1,3,5,6};
        int res = searchInsert(nums, 7);
        cout << res;
    }
};
