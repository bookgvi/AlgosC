#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class MinimumAbsoluteDifference {

public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        vvi res;
        int minDiff = INT_MAX, len = (int) arr.size();
        for (int i = 0; i < len - 1; i += 1) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }
        for (int i = 0; i < len - 1; i += 1)
            if (arr[i + 1] - arr[i] == minDiff) res.push_back({arr[i], arr[i + 1]});
        return res;
    }

// TLE
    vector<vector<int>> minimumAbsDifference_BruteForce(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, vvi> prep;
        int len = (int) arr.size(), minV = INT_MAX;
        for (int i = 0; i < len - 1; i += 1) {
            for (int j = i + 1; j < len; j += 1) {
                int key = abs(arr[i] - arr[j]);
                if (prep.count(key)) {
                    vvi values = prep[key];
                    int first = arr[i], second = arr[j];
                    if (first > second) swap(first, second);
                    values.push_back({first, second});
                    prep[key] = values;
                } else {
                    vvi values;
                    int first = arr[i], second = arr[j];
                    if (first > second) swap(first, second);
                    values.push_back({first, second});
                    prep[key] = values;
                }
                minV = min(minV, key);
            }
        }
        return prep[minV];
    }

    void work() {
        vi arr = {4, 2, 1, 3};
        vvi res = minimumAbsDifference(arr);
    }
};