#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/
 * */
class KdiffPairsinanArray {
public:
    int findPairs(vector<int> &nums, int k) {
        int count = 0;
        unordered_map<int, int> map;
        for (auto elt : nums)
            map[elt] += 1;
        for (auto r : map)
            count += k ? (int) map.count(r.first - k) : r.second > 1;
        return count;
    }

    void work() {
        vector<int> nums = {1, 2, 3, 1, 2};
        int k = 1;
        int res = findPairs(nums, k);
        cout << "fin\n";
    }
};