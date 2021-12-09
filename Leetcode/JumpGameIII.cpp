#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/jump-game-iii/submissions/
 * */
class JumpGameIII {
private:
    vvi g;
    vi used;
    bool result = false;

    void addEdge(int start, int end) {
        if (start - end >= 0) g[start].push_back(start - end);
        if (start + end < (int) g.size()) g[start].push_back(start + end);
    }

    void build(vi &arr) {
        int len = (int) arr.size();
        g = vvi(len, vi());
        used = vi(len, 0);
        for (int i = 0; i < len; i += 1) {
            addEdge(i, arr[i]);
        }
    }

    void dfs(int v, vi &arr) {
        used[v] = 1;
        if (arr[v] == 0) result = 1;
        for (auto next : g[v]) {
            if (used[next] == 0) {
                dfs(next, arr);
            }
        }
    }

public:
    void work() {
        vi arr = {0, 0, 0, 0};
        int start = 1;
        build(arr);
        dfs(start, arr);
        cout << result << "\n";
    }
};