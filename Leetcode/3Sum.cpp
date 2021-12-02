#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/3sum/
 * */
class ThreeSum {
public:
    // TLE
    vector<vector<int>> threeSum(vector<int> &nums) {
        vvi ans, tmpAns;
        set<vector<int>> ansSet;
        for (int i = 0, len = (int) nums.size(); i < len; i += 1)
            for (int j = i + 1; j < len; j += 1)
                for (int k = j + 1; k < len; k += 1)
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet{nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        ansSet.insert(triplet);
                        tmpAns.push_back(triplet);
                    }
        for (auto elt : ansSet)
            ans.push_back(elt);
        return ans;
    }

    // TLE
    vector<vector<int>> threeSumV2(vector<int> &nums) {
        set<vector<int>> ansSet;
        sort(nums.begin(), nums.end());
        for (int i = 0, len = (int) nums.size(); i < len && nums[i] <= 0; i += 1)
            for (int j = i + 1; j < len; j += 1)
                for (int k = len - 1; k > j && nums[k] >= 0; k -= 1)
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet{nums[i], nums[j], nums[k]};
                        ansSet.insert(triplet);
                    }
        vector<vector<int>> ans(ansSet.size(), {});
        int i = 0;
        for (const auto &elt : ansSet) ans[i++] = elt;
        return ans;
    }

    int binSearch(int i, int j, vector<int> &arr) {
        int len = arr.size(), l = 0, r = len - 1, n = -(arr[i] + arr[j]);
        while(r - l >= 0) {
            int mid = (r + l) >> 1;
            if (arr[mid] == n && mid != i && mid != j) return mid;
            else if (arr[mid] < n) l = mid + 1;
            else r = mid - 1;
        }
        return INT_MIN;
    }

    // This is Accepted
    vector<vector<int>> threeSumV3(vector<int> &nums) {
        vector<vector<int>> ans;
        set<vector<int>> ansSet;
        sort(nums.begin(), nums.end());
        int res;
        for (int i = 0, len = (int) nums.size(); i < len; i += 1) {
            if (i > 1 && nums[i] == nums[i - 2]) continue;
            for (int j = i + 1; j < len; j += 1) {
                res = binSearch(i, j, nums);
                if (res != INT_MIN) {
                    vector<int> triplet{nums[i], nums[j], nums[res]};
                    sort(triplet.begin(), triplet.end());
                    ansSet.insert(triplet);
                }
            }
        }

        for (const auto &elt : ansSet) ans.push_back(elt);
        return ans;
    }

    void work() {
        vi nums = {0,3,0,1,1,-1,-5,-5,3,-3,-3,0};
        vvi ans = threeSumV3(nums);
        cout << "res";
    }
};