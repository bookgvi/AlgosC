#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/is-subsequence/
 * */
class IsSubsequence {
public:
    bool isSubsequence(string s, string t) {
        deque<char> q;
        for (char ch : s) q.push_back(ch);
        if ((int) q.size())
            for (char ch : t) if (q.front() == ch) q.pop_front();
        return !(int) q.size();
    }

    void work() {
        string s = "abc", t = "";
        bool res = isSubsequence(s, t);
        cout << "res";
    }
};