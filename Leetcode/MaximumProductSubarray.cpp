#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<long> vl;

/*
 * https://leetcode.com/problems/maximum-product-subarray/submissions/
 * */
class MaximumProductSubarray {
private:
    vl st;
    int n;
    void buildSt(vi &nums) {
        n = (int) nums.size();
        st = vl(n << 1, 0);
        for (int i = 0; i < n; i += 1)
            st[i + n] = nums[i];
        for (int i = n - 1; i > 0; i -= 1)
            st[i] = st[i << 1] * st[i << 1 | 1];
    }

    int query(int l, int r) {
        int res = 1;
        r += 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res *= st[l++];
            if (r & 1) res *= st[--r];
        }
        return res;
    }
public:
    // TLE
    int maxProductV1(vector<int> &nums) {
        if ((int) nums.size() == 1) return nums[0];
        int ans = INT_MIN;
        buildSt(nums);
        for (int l = 0; l < n; l += 1) {
            ans = max(ans, nums[l]);
            for (int r = l + 1; r < n; r += 1)
                ans = max(ans, query(l, r));
        }
        return ans;
    }

    // Accepted
    int maxProductV2(vector<int> &nums) {
        int len = (int) nums.size(), start = 0, end = len - 1, ans = nums[0], prodL = 1, prodR = 1;
        for (int l = start; l <= end; l += 1) {
            int r = end - l;
            prodL = nums[l] * prodL;
            prodR = nums[r] * prodR;
            ans = max(ans, max(prodL, prodR));
            if (prodL == 0) prodL = 1;
            if (prodR == 0) prodR = 1;
        }
        return ans;
    }
    void work() {
        vi nums = {6,3,6,-2,3,1,1,1,-1,4,2,4,-1,-4,0,-5,-2,6,4,-1,-3,0,5,5,1,0,0,1,5,-4,0,6,4,-4,-3,-6,-2,-2,-4,3,5,-5,-1,-3,-1,-1,-6,-5,-1,-1,-1,0,-6,2,1,-1,5,-6,-5,-3,6,4,3,-2,4,-2,-3,-1,0,-1,-1,-1,4,0,6,-1,4,4,-3,4,-3,-2,0,4,-3,-1,1,-2,0,-4,6,0,2,2,0,0,-2,1,4,-3};
        int res = maxProductV2(nums);
        cout << "res";
    };
};