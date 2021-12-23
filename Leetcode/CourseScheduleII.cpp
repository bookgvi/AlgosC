#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/course-schedule-ii/submissions/
 * */
class CourseScheduleII {
private:
    vvi g;
    vi used, p, cycle, topo, time_in, time_out;
    int isCycle = 0, time = 0, cycle_start, cycle_end;

    void addEdge(int start, int end) {
        g[start].push_back(end);
    }

    void dfs(int v) {
        used[v] = 1;
        time_in[v] = time++;
        for (auto next : g[v]) {
            if (used[next] == 0) {
                p[next] = v;
                dfs(next);
            } else if (used[next] == 1) {
                isCycle = 1;
                cycle_start = next;
                cycle_end = v;
            }
        }
        if (!isCycle) topo.push_back(v);
        used[v] = 2;
        time_out[v] = time++;
    }

    void build(int numCourses, vvi &arr) {
        init(numCourses);
        for (auto i = 0, len = (int) arr.size(); i < len; i += 1) {
            addEdge(arr[i].front(), arr[i].back());
        }
    }

    void init(int len) {
        g = vvi(len);
        used = vi(len, 0), p = vi(len, 0), time_in = vi(len, 0), time_out = vi(len, 0);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        if (numCourses == 1) return {0};
        build(numCourses, prerequisites);
        for (auto v = 0; v < numCourses && !isCycle; v += 1)
            if (used[v] == 0) dfs(v);
        if (isCycle) return {};
        return topo;
    }

    void work() {
//        vvi arr = {{1,0},{2,0},{3,1},{3,2}};
        vvi arr = {{1, 0}, {0, 1}};
        int n = 4;
        vi res = findOrder(n, arr);
        cout << "re";
    }
};