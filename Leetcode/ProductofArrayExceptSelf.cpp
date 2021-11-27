#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

/*
 * https://leetcode.com/problems/product-of-array-except-self/
 * */

class SegmentTree {
public:
    vi build(vi &arr) {
        int n = (int) arr.size();
        vi st(n << 1, 0);
        for (int i = 0; i < n; i += 1)
            st[i + n] = arr[i];
        for (int i = n - 1; i > 0; i -= 1)
            st[i] = st[i << 1] * st[i << 1 | 1];
        return st;
    }

    int query(int l, int r, vi &st) {
        int n = (int) st.size() >> 1, res = 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res *= st[l++];
            if (r & 1) res *= st[--r];
        }
        return res;
    }

    vi modify(int v, int value, vi &st) {
        int n = (int) (st.size() >> 1);
        for (st[v += n] = value; v > 1; v >>= 1)
            st[v >> 1] = st[v] * st[v ^ 1];
        return st;
    }
};

class ProductofArrayExceptSelf {
public:
    vector<int> productExceptSelfTrivial(vector<int> &nums) {
        vector<int> ans;
        int len = (int) nums.size(), prod = 1;
        for (int j = 0; j < len; j += 1) {
            for (int i = j + 1, k = 0; k < len - 1; i += 1, k += 1) {
                prod *= nums[i % len];
            }
            ans.push_back(prod);
            prod = 1;
        }
        return ans;
    }

    vector<int> productExceptSelfST(vector<int> &nums){
        int len = (int) nums.size();
        vi ans;
        SegmentTree sTree;
        vi st = sTree.build(nums);
        for (auto i = 0; i != len; i += 1) {
            if (i == 0) ans.push_back(sTree.query(i + 1, len, st));
            else {
                int start1 = 0, end1 = i;
                int start2 = min(len, i + 1), end2 = len;
                int mul1 = sTree.query(start1, end1, st);
                int mul2 = sTree.query(start2, end2, st);
                int prod = mul1 * mul2;
                ans.push_back(prod);
            }

        }
        return ans;
    }

    void work() {
        SegmentTree st;
        vector<int> nums = {1, 2};
        vi newSt = st.build(nums);
        int query = st.query(1, nums.size() - 1, newSt);
        int query2 = st.query(1, 1, newSt);
        vector<int> prod = productExceptSelfTrivial(nums);
        vector<int> prod2 = productExceptSelfST(nums);
    }
};

