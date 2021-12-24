#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/subsets/submissions/
 * */
class Subsets {
private:
    vi getArr(int set, vi &arr) {
        vi res;
        for (int i = 0; i < 32; i += 1)
            if (set & (1 << i)) res.push_back(arr[i]);
        return res;
    }

    int getSet(int count) {
        int set = 0;
        for (int i = 0; i < count; i += 1)
            set |= (1 << i);
        return set;
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vvi res;
        int set = getSet((int) nums.size());
        int b = 0;
        do {
            res.push_back(getArr(b, nums));
        } while ((b = (b - set) & set));
        return res;
    }

    void work() {
        vi arr = {10};
        vvi res = subsets(arr);
        cout << "res";
    }
};