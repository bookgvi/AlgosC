#include <bits/stdc++.h>

using namespace std;

class IntervalListIntersections {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        int it1 = 0, it2 = 0, len1 = firstList.size(), len2 = secondList.size();
        vector<vector<int>> res;
        vector<int> pairs(2, 0);
        while (it1 < len1 && it2 < len2) {
            int a = max(firstList[it1][0], secondList[it2][0]);
            int b = min(firstList[it1][1], secondList[it2][1]);
            if (b >= a) {
                pairs[0] = a, pairs[1] = b;
                res.push_back(pairs);
            }
            if (firstList[it1][1] < secondList[it2][1]) {
                it1 += 1;
            } else {
                it2 += 1;
            }
        }
        return res;
    }

    void work() {
        vector<vector<int>> firstList = {{0,  2},
                                         {5,  10},
                                         {13, 23},
                                         {24, 25}},
                secondList = {{1,5},{8,12},{15,24},{25,26}};
        vector<vector<int>> res = intervalIntersection(firstList, secondList);
        cout << "res";
    }

};
