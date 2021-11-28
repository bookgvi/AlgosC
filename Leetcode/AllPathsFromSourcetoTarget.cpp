#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/all-paths-from-source-to-target/
 * */
const int maxV = 15;

class AllPathsFromSourcetoTarget {
public:
    vvi g, pathArr;
    vi path;


    void init(vvi graph) {
        g = graph;
    }

    void traverse(int v) {
        path.push_back(v);
        if (v == g.size() - 1) pathArr.push_back(path);
        else {
            for (auto next : g[v])
                traverse(next);
        }
        path.pop_back();
    }


    void work() {
        vvi graph = {{1, 2},
                     {3},
                     {3},
                     {}};
        init(graph);
        traverse(0);
    }

};