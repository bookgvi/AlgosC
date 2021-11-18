#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {

public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> resV;
        nums = sort(nums);
        for (int i = 1; i <= nums.size(); i += 1) {
            int res = binarySearch(i, nums);
            if (res < 0) resV.push_back(i);
        }
        return resV;
    }

    vi sort(vi arr) {
        int len = arr.size(), b = 8, dw = 4;
        vi t(len, 0);
        for (int p = 0; p < dw; p += 1) {
            vi count(1 << b, 0);
            for (int elt : arr)
                count[((elt ^ INT32_MIN) >> (p * b)) & ((1 << b) - 1)] += 1;
            for (int i = 1; i < 1 << b; i += 1)
                count[i] += count[i - 1];
            for (int i = len - 1; i >= 0; i -= 1)
                t[--count[((arr[i] ^ INT32_MIN) >> (p * b)) & ((1 << b) - 1)]] = arr[i];
            for (int i = 0; i < len; i += 1)
                arr[i] = t[i];
        }
        return arr;
    }

    int binarySearch(int n, vi &arr) {
        int len = arr.size(), l = 0, r = len - 1;
        while (r - l >= 0) {
            int mid = (r + l) >> 1;
            if (arr[mid] == n) return mid;
            else if (arr[mid] <= n) l = mid + 1;
            else r = mid - 1;
        }
        return -(l + 1);
    }
};
