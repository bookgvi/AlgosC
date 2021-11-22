#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vp;
typedef pair<int, int> pii;


class BackPack {
public:
    vvi solve(int weight, vp things) {
        int count = things.size();
        vi weights(weight + 1, 0);
        vvi d(count, weights);
        for (int i = 1; i <= count; i += 1) {
            for (int w = 1; w <= weight; w += 1) {
                if (w - things[i].first >= 0 && d[i - 1][w] < d[i - 1][w - things[i].first] + things[i].second)
                    d[i][w] = d[i - 1][w - things[i].first] + things[i].second;
                else
                    d[i][w] = d[i - 1][w];
            }
        }
        return d;
    }

    void work() {
        int w = 4;
        pii t0, t1, t2, t3, t4;
        t0.first = 0, t0.second = 0;
        t1.first = 1, t1.second = 60;
        t2.first = 2, t2.second = 100;
        t3.first = 2, t3.second = 100;
        vp things;
        things.push_back(t0);
        things.push_back(t1);
        things.push_back(t2);
        things.push_back(t3);

        int count1 = things.size();
        BackPack bp;
        vvi res = bp.solve(w, things);
        vi ans;
        for (int i = count1 - 1; i > 0; i -= 1) {
            if (res[i][w] != res[i - 1][w]) {
                ans.push_back(i);
                w -= things[i].first;
            }
        }

        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
};