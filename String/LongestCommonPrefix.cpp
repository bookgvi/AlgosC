#include <bits/stdc++.h>

using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/*
 * https://leetcode.com/problems/longest-common-prefix/submissions/
 * */
class Vertex {
public:
    string label;
    string suffix;
    unordered_map<string, Vertex *> toNext;
    int lcp;

    Vertex(string label, string suffix) {
        this->label = label;
        this->suffix = suffix;
        this->lcp = 0;
    }
};

class Bor {
private:
    Vertex *root = new Vertex("root", "");
public:
    int maxLCP = 0;
    Vertex *maxLcpV = new Vertex("", "");

    void addKeyWord(string &keyWord) {
        Vertex *curVertex = root;
        string suffix;
        for (int i = 0, len = (int) keyWord.length(); i < len; i += 1) {
            string label = keyWord.substr(i, 1);
            suffix += label;
            if (!curVertex->toNext.count(label)) {
                curVertex->toNext[label] = new Vertex(label, suffix);
                curVertex->toNext[label] ->lcp = 1;
            } else {
                curVertex->toNext[label]->lcp += 1;
                if (maxLCP <= curVertex->toNext[label]->lcp) maxLcpV = curVertex->toNext[label];
                maxLCP = max(maxLCP, curVertex->toNext[label]->lcp);
            }

            curVertex = curVertex->toNext[label];
        }
    }

};

class LongestCommonPrefix {
private:
    vvi classesV;

    // not used
    vi suffixArray(string &str) {
        int len = (int) str.length(), b = 8;
        vi p(len, 0), c(len, 0), count(1 << b, 0);
        for (int i = 0; i < len; i += 1)
            count[str[i]] += 1;
        for (int i = 1; i < 1 << b; i += 1)
            count[i] += count[i - 1];
        for (int i = len - 1; i >= 0; i -= 1)
            p[--count[str[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < len; i += 1) {
            if (str[p[i]] != str[p[i - 1]]) classes += 1;
            c[p[i]] = classes - 1;
        }
        classesV.push_back(c);
        vi pn(len, 0), cn(len, 0);
        for (int h = 0; 1 << h < len; h += 1) {
            for (int i = 0; i < len; i += 1) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0) pn[i] += len;
            }
            count = vi(1 << b, 0);
            for (int i = 0; i < len; i += 1)
                count[c[pn[i]]] += 1;
            for (int i = 1; i < len; i += 1)
                count[i] += count[i - 1];
            for (int i = len - 1; i >= 0; i -= 1)
                p[--count[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < len; i += 1) {
                int mid1 = (p[i] + (1 << h)) % len, mid2 = (p[i - 1] + (1 << h)) % len;
                if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes += 1;
                cn[p[i]] = classes - 1;
            }
            for (int i = 0; i < len; i += 1)
                c[i] = cn[i];
            classesV.push_back(c);
        }
        return p;
    }

public:
    //not used
    string longestCommonPrefixT(vector<string> &strs) {
        string allStr = "";
        for (auto eltStr : strs) allStr += eltStr;
        vi p = suffixArray(allStr);
        int ans = 0, i = 0, j = 14;
        for (auto k = 0; k < classesV.size(); k += 1) {
            if (classesV[k][i] == classesV[k][j]) {
                ans += 1 << k;
                i += 1 << k;
                j += 1 << k;
            }
        }
        return "";
    }

    string longestCommonPrefix(vector<string> &strs) {
        Bor bor;
        if (strs.size() < 2) return strs[0];
        for (string kw : strs)
            bor.addKeyWord(kw);

        return bor.maxLCP == strs.size() ? bor.maxLcpV->suffix : "";
    }

    void work() {
//        vs strs = {"flower", "flow", "flight"};
//        vs strs = {""};
//        vs strs = {"a"};
//        vs strs = {"a", "b", "c"};
//        vs strs = {"a", "ab"};
//        vs strs = {"a", "ab", "abc"};
//        vs strs = {"dog","racecar","car"};
        vs strs = {"reflower","flow","flight"};
        string str = longestCommonPrefix(strs);
//        string str = longestCommonPrefixT(strs);
        cout << str;
    }
};