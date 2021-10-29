#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class LongestValidParentheses {
public:
    int longestValidParentheses(string s) {
        vi stack;
        int sLen = s.length(), maxLen = 0;
        stack.push_back(-1);
        for (int i = 0; i < sLen; i += 1) {
            if (s[i] == ')') {
                stack.pop_back();
                if (stack.empty()) {
                    stack.push_back(i);
                }
                else {
                    maxLen = max(maxLen, i - stack.back());
                }
            } else {
                stack.push_back(i);
            }
        }
        return maxLen;
    }

    pair<int, int> checkIt(string s) {
        vi stack;
        pair<int, int> seq;
        int sLen = s.length();
        int maxLen = 0, startPos = 0;
        stack.push_back(-1);
        for (int i = 0; i < sLen; i += 1) {
            if (s[i] == ')') {
                stack.pop_back();
                if (stack.empty()) {
                    stack.push_back(i);
                }
                else {
                    maxLen = max(maxLen, i - stack.back());
                    startPos = stack.back() + 1;
                }
            } else {
                stack.push_back(i);
            }
        }
        seq.first = startPos;
        seq.second = maxLen;
        return seq;
    }
};
