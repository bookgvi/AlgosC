#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef set<vector<int>> svi;

/*
 * https://leetcode.com/problems/4sum/submissions/
 * */
class FourSum {
private:
    void sort(vi &arr) {
        int len = (int) arr.size(), b = 8, dw = 4;
        vi t(len, 0);
        for (int p = 0; p < dw; p += 1) {
            vi count(1 << b, 0);
            for (auto const &elt : arr)
                count[((elt ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)] += 1;
            for (int i = 1; i < 1 << b; i += 1)
                count[i] += count[i - 1];
            for (int i = len - 1; i >= 0; i -= 1)
                t[--count[((arr[i] ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)]] = arr[i];
            for (int i = 0; i < len; i += 1)
                arr[i] = t[i];
        }
    }

    int binSearch(int f, int s, int t, int target, vi &arr) {
        int len = (int) arr.size(), l = 0, r = len - 1;
        long n = (long) arr[f] + (long) arr[s] + (long) arr[t];
        while (r - l >= 0) {
            int mid = (r + l) >> 1;
            if (mid != f && mid != s && mid != t && arr[mid] == target - n)
                return mid;
            else if (arr[mid] < target - n) l = mid + 1;
            else r = mid - 1;
        }
        return INT_MIN;
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vvi res;
        svi resSet;
        sort(nums);
        for (int i = 0, len = (int) nums.size(); i < len; i += 1) {
            if (i > 2 && nums[i] == nums[i - 2]) continue;
            for (int j = i + 1; j < len; j += 1)
                for (int k = j + 1; k < len; k += 1) {
                    int fourth = binSearch(i, j, k, target, nums);
                    if (fourth != INT_MIN) {
                        vi sumV = {nums[i], nums[j], nums[k], nums[fourth]};
                        sort(sumV);
                        resSet.insert(sumV);
                    }
                }
        }
        for (auto const &elt : resSet) res.push_back(elt);
        return res;
    }
    void work() {
        vi nums = {1000000000,1000000000,1000000000,1000000000};
        fourSum(nums, 0);
        cout << "res";
    }
};