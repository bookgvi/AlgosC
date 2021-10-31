#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class GrassHopper {
public:
    pair<vi, vi> solve(int k, vi coinOnColumns) {
        int colCount = (int) coinOnColumns.size() + 1;
        vi maxSumm(colCount, 0), cols(colCount, 0);
        pair<vi, vi> res;
        for (int i = 1; i < colCount; i += 1) {
            int numMax = i - 1;
            for (int j = max(i - k, 1); j <= i - 1; j += 1) {
                if (maxSumm[j] > maxSumm[numMax])
                    numMax = j;
            }
            maxSumm[i] = maxSumm[numMax] + coinOnColumns[i];
            cols[i] = numMax;
        }
        res.first = maxSumm;
        res.second = cols;
        return res;
    }

    pair<vi, vi> solve1(int k, vi coinOnColumns) {
        int colCount = (int) coinOnColumns.size() + 1;
        vi values(colCount, 0), cols(colCount, 0);
        pair<vi, vi> res;
        for (int i = 1; i < colCount; i += 1) {
            values[i] = coinOnColumns[i];
            cols[i] = 1;
            for (int step = 1; step <= k; step += 1) {
                if (i - step >= 0 && values[i - step] + coinOnColumns[i] > values[i]) {
                    values[i] = values[i - step] + coinOnColumns[i];
                    cols[i] = step;
                }
            }
        }
        res.first = values;
        res.second = cols;
        return res;
    }
};

//int main() {
//    GrassHopper gh;
//    vi coinOnColumns = {0, 1, 2, -3, 5, -4, -1, 3};
//    pair<vi, vi> res = gh.solve(3, coinOnColumns);
//    pair<vi, vi> res1 = gh.solve1(3, coinOnColumns);
//
//    vi ans, steps = res.second;
//    int k = steps.size() - 1;
//    do {
//        k = steps[k];
//        ans.push_back(k);
//    } while (k > 0);
//
//    vi ans1;
//    steps = res1.second;
//    k = steps.size() - 1;
//    do {
//        k -= steps[k];
//        ans1.push_back(k);
//    } while (k > 0);
//
//    cout << "finish...\n";
//}
