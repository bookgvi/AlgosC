#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/merge-intervals/submissions/
 * */
class MergeIntervals {
private:
    vvi sort(vvi &arr) {
        int len = (int) arr.size(), b = 1e4 + 1;
        vvi t(len);
        vi count(b, 0);
        for (auto pair : arr)
            count[pair[0]] += 1;
        for (int i = 1; i < b; i += 1)
            count[i] += count[i - 1];
        for (int i = len - 1; i >= 0; i -= 1)
            t[--count[arr[i].front()]] = arr[i];
        return t;
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vvi sorted = sort(intervals), res;
        int isMerge = 1;
        while (isMerge > 0) {
            for (auto i = 0, len = (int) sorted.size(); i < len; i += 2) {
                int fc = sorted[i].front();     // first current
                int sc = sorted[i].back();      // second current
                int fn = -1, sn = -1;
                if (i + 1 < len) {
                    fn = sorted[i + 1].front(); // first next
                    sn = sorted[i + 1].back();  // second next
                }
                vi pair;
                if (fn != -1 && sn != -1 && sc >= fn) {
                    pair.push_back(fc), pair.push_back(max(sc, sn));
                    res.push_back(pair);
                    isMerge += 1;
                } else if (fn != -1 && sn != -1 && fc == fn) {
                    pair.push_back(fc), pair.push_back(max(sc, sn));
                    res.push_back(pair);
                    isMerge += 1;
                } else {
                    res.push_back(sorted[i]);
                    i -= 1;
                }
            }
            sorted = res;
            res = {};
            isMerge -= 1;
        }
        return sorted;
    }

    void work() {
        vvi arr = {{4,  5},
                   {2,  6},
                   {1,  3},
                   {8,  10},
                   {15, 18}};
        vvi res = merge(arr);
        cout << "res";
    }
};