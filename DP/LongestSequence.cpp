#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class LongestSequence {
public:
    pair<vi, vi> solve(vi nums) {
        pair<vi, vi> res;
        vi d, last;
        d.push_back(1);
        int counter = 0, len = nums.size();
        for (int i = 1; i < len; i += 1) {
            int maxSeq = 0;
            for (int k = i - 1; k >= 0; k -= 1){
                if (d[k] > maxSeq && nums[i] > nums[k]) {
                    maxSeq = d[k];
                    last.push_back(k);
                }
            }
            d.push_back(maxSeq + 1);
        }
        res.first = d;
        res.second = last;
        return res;
    }
};

//int main() {
//    LongestSequence ls;
//    vi nums = {1, 4, 2, 5, 6, 3, 7};
//    pair<vi, vi> res = ls.solve(nums);
//}