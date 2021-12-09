#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class RMQ {
private:
    int n;
    vi st, arr;

    void init() {
        arr = {112, 3, 4, 9, 6, 4, 7, 8, 12, 13, 15, 11};
        n = (int) arr.size();
        st = vi(n << 1, 0);
    }

    void sanitize(int &v) {
        sanitize(v, v);
    }


    void sanitize(int &l, int &r) {
        if (l > r) swap(l, r);
        l = max(l, 0);
        l = min(l, n - 1);
        r = min(r, n - 1);
        r = max(r, 0);
    }


    void buildST() {
        for (int i = 0; i < n; i += 1)
            st[i + n] = arr[i];
        for (int v = n - 1; v > 0; v -= 1)
            st[v] = min(st[v << 1], st[v << 1 | 1]);
    }

    void modify(int v, int value) {
        sanitize(v);
        for (st[v += n] = value; v > 1; v >>= 1)
            st[v >> 1] = min(st[v], st[v ^ 1]);
    }

    /**
    * @return min[l, r]
    */
    int queryST(int l, int r) {
        int res = INT_MAX;
        sanitize(l, r);
        r += 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, st[l++]);
            if (r & 1) res = min(res, st[--r]);
        }
        return res;
    }

public:

    void work() {
        init();
        buildST();
        int res = queryST(0, n);
        int res1 = queryST(8, 4);
        modify(n + 5, 2);
        cout << "res";
    }

};