#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 *  0 --- 2
 *  |       \ 4
 *  |       /
 *  1 --- 3
 *
 * */
class Graph {
private:
    const int n = 5;
    vvi g;
    vi used, p, mst, cycle, time_in, time_out;
    int isCycle = 0, time = 0, cycle_start = 0, cycle_end = 0;

    void reset() {
        used = vi(n, 0), p = vi(n, 0), cycle = vi(),
        time_in = vi(n, 0), time_out = vi(n, 0);
        isCycle = 0, time = 0;
    }

    void addEdge(int start, int end) {
        g[start].push_back(end);
    }

    void build() {
        addEdge(0, 1);
        addEdge(0, 2);
        addEdge(1, 3);
        addEdge(1, 0);
        addEdge(3, 1);
        addEdge(3, 4);
        addEdge(2, 0);
        addEdge(2, 4);
        addEdge(4, 2);
        addEdge(4, 3);
    }

    void dfs(int v) {
        used[v] = 1;
        time_in[v] = time++;
        for (auto next: g[v]) {
            if (used[next] == 0) {
                p[next] = v;
                dfs(next);
            } else if (used[next] == 1 && next != p[v]) {
                isCycle = 1;
                cycle_start = next;
                cycle_end = v;
            }
        }
        used[v] = 2;
        time_out[v] = time++;
    }

    void bfs(int v) {
        reset();
        int cur;
        queue<int> vq;
        used[v] = 1;
        time_in[v] = time++;
        vq.push(v);
        while(!vq.empty()) {
            cur = vq.front();
            time_out[cur] = time++;
            mst.push_back(cur);
            vq.pop();
            for(auto next : g[cur]) {
                if (used[next] == 0) {
                    used[next] = 1;
                    time_in[next] = time++;
                    vq.push(next);
                }
            }
        }
    }

    void getCycle() {
        while(cycle_end != cycle_start) {
            cycle.push_back(cycle_end);
            cycle_end = p[cycle_end];
        }
        cycle.push_back(cycle_start);
    }

public:
    Graph() : g(n, vi({})), used(n, 0), p(n, 0), time_in(n, 0), time_out(n, 0) {}

    void work() {
        build();
        dfs(0);

        if (isCycle) {
            getCycle();
            cout << "Cycle:\n";
            for (auto elt = cycle.rbegin(); elt != cycle.rend(); ++elt)
                printf("%d(%d, %d)\n", *elt, time_in[*elt], time_out[*elt]);
        }

        bfs(0);
        cout << "\nBFS:\n";
        for(auto elt = mst.begin(); elt != mst.end(); ++elt)
            printf("%d(%d, %d)\n", *elt, time_in[*elt], time_out[*elt]);
    }
};