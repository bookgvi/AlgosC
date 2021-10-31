#include <bits/stdc++.h>

using namespace std;

int binSearchL(vector<int> &nums, int target) {
    int len = nums.size(), k = len - 1;
    if (len > 0) {
        for (int i = len >> 1; i > 0; i >>= 1)
            while (k - i >= 0 && nums[k - i] >= target) k -= i;
        if (nums[k] == target) return k;
    }
    return -1;
}

int binSearchR(vector<int> &nums, int target) {
    int len = nums.size(), k = 0;
    if (len > 0) {
        for (int i = len >> 1; i > 0; i >>= 1)
            while (k + i < len && nums[k + i] <= target) k += i;
        if (nums[k] == target) return k;
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int l = binSearchL(nums, target);
    int r = binSearchR(nums, target);
    vector<int> res;
    res.push_back(l);
    res.push_back(r);
    return res;
}

//int main() {
//    vector<int> nums = {};
//    int target = 0;
//    vector<int> res = searchRange(nums, target);
//
//    for (int i = 0; i < res.size(); i += 1)
//        cout << res[i] << "\n";
//}

