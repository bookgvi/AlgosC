#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef unordered_map<int, vector<int>> umvi;
typedef unordered_set<int> usi;

class SetWithUniqElts {
private:
    umvi g;
    usi used;
    vi p, set;

    vi sort(vi &arr) {
        int len = (int) arr.size(), b = 8, dw = 4;
        vi t(len, 0);
        for (int p = 0; p < dw; p += 1) {
            vi count(1 << b, 0);
            for (int elt : arr)
                count[((elt ^ INT_MIN) >> (p *b)) & ((1 << b) - 1)] += 1;
            for (int i = 1; i < 1 << b; i += 1)
                count[i] += count[i - 1];
            for (int i = len - 1; i >= 0; i -= 1)
                t[--count[((arr[i] ^INT_MIN) >> (p * b)) & ((1 << b) - 1)]] = arr[i];
            for (int i = 0; i < len; i += 1)
                arr[i] = t[i];
        }
        return arr;
    }

    void init(vvi &qs) {
        for (auto l : qs) {
            if (!(int) l.size()) continue;
            int key = l[0];
            for (auto i = 1; i <= (int) l.size(); i += 1) {
                g[key].push_back(l[i - 1]);
                g[l[i - 1]].push_back(key);
            }
        }
    }

    void dfs(int v) {
        used.insert(v);
        set.push_back(v);
        for (auto next : g[v]) {
            if (!used.count(next)) {
                dfs(next);
            }
        }
    }

    vi buildSet(vvi &qs) {
        init(qs);
        for (auto l : qs) {
            if (!(int) l.size()) continue;
            if (!used.count(l[0])) {
//                set.push_back(l[0]);
                dfs(l[0]);
            }
        }
        return sort(set);
    }
public:
    void work() {
        vvi quasiSet = {{6, 1, 2, 3, 4},
                        {6, 1, 3, 5, 7, 8}};
        vi res = buildSet(quasiSet);
        cout << "res";
    }
};