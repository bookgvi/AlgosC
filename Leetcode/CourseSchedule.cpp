#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/course-schedule
 * */
class CourseSchedule {
private:
    vvi g;
    vi used, p, time_in, time_out, topo;
    int isCycle = 0, time = 0;

    void addEdge(int start, int end) {
        g[start].push_back(end);
    }

    void init(int numCourses, vvi &arr) {
        g = vvi(numCourses), used = vi(numCourses, 0), p = vi(numCourses, 0), time_in = vi(numCourses, 0),
        time_out = vi(numCourses, 0);
        for (int i = 0; i < (int) arr.size(); i += 1)
            addEdge(arr[i].front(), arr[i].back());
    }

    void dfs(int v) {
        used[v] = 1;
        time_in[v] = time++;
        for (auto next : g[v]) {
            if (used[next] == 0) {
                p[next] = v;
                dfs(next);
            } else if (used[next] == 1) isCycle = 1;
        }
        used[v] = 2;
        time_out[v] = time++;
        topo.push_back(v);
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if ((int) prerequisites.size() < 1) return true;
        unordered_set<int> vertex;
        init(numCourses, prerequisites);
        for (auto elt : prerequisites) {
            for (auto v : elt) {
                vertex.insert(v);
                if (used[v] == 0) dfs(v);
            }
        }
        if (isCycle) return false;
        return topo.size() == vertex.size();
    }

    void work() {
        vvi arr =
        {{1,4},{2,4},{3,1},{3,2}};
        bool res = canFinish(5, arr);
        cout << "res";
    }
};