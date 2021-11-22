#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class LongestSequence {
public:
    pair<vi, vi> solve(vi nums) {
        int counter = 0, len = nums.size();
        pair<vi, vi> res;
        vi d, p(len, -1);
        d.push_back(1);
        for (int i = 1; i < len; i += 1) {
            d.push_back(1);
            for (int k = i - 1; k >= 0; k -= 1) {
                if (d[k] + 1 > d[i] && nums[i] > nums[k]) {
                    d[i] = d[k] + 1;
                    p[i] = k;
                }
            }
        }
        int ans = d[0], elt = 0;
        for (int i  = 0; i < len; i += 1) {
            if (ans < d[i]) ans = d[i];
            elt = max(elt, i);
        }
        vi seq;
        while(elt != -1) {
            seq.push_back(elt);
            elt = p[elt];
        }
        res.first = d;
        res.second = seq;
        return res;
    }


    void work() {
        LongestSequence ls;
        vi nums = {1, 4, 2, 5, 6, 3, 7};
        pair<vi, vi> res = ls.solve(nums);
    }
};