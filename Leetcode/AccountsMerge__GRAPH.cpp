#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<string>> vvs;
typedef vector<string> vs;
typedef unordered_map<string, vs> umvs;
typedef unordered_set<string> uss;
/*
 * https://leetcode.com/problems/accounts-merge/
 * */
class AccountsMerge {
private:
    umvs g;
    uss used;
    vvs ans;

    int comparator(string &str1, string &str2) {
        int len1 = (int) str1.length(), len2 = (int) str2.length(),
                len = min(len1, len2);
        for (int i = 0; i < len; i += 1)
            if (str1[i] - str2[i] != 0) return str1[i] - str2[i];
        return len1 - len2;
    }

    vs sort(int start, int end, vs &arr) {
        return arr.size() > 15 ? mergeSort(start, end, arr) : insertSort(start, end, arr);
    }

    vs insertSort(int start, int end, vs &arr) {
        end = min(end, (int) arr.size() - 1);
        for (int i = start; i <= end; i += 1)
            for (int j = i; j > start && comparator(arr[j - 1], arr[j]) > 0; j -= 1)
                swap(arr[j - 1], arr[j]);
        return arr;
    }

    vs mergeSort(int start, int end, vs &arr) {
        end -= start;
        for (int i = 1; i < end; i <<= 1)
            for (int j = 0; j < end - i; j += i << 1)
                merge(j, j + i, min(end, j + (i << 1)), arr, start);
        return arr;
    }

    void merge(int l, int mid, int r, vs &arr, int delta) {
        int it1 = 0, it2 = 0;
        vs merge(r - l);
        l += delta, mid += delta, r += delta;
        while (l + it1 < mid && mid + it2 < r) {
            if (comparator(arr[l + it1], arr[mid + it2]) < 0) {
                merge[it1 + it2] = arr[l + it1];
                it1 += 1;
            } else {
                merge[it1 + it2] = arr[mid + it2];
                it2 += 1;
            }
        }
        while (l + it1 < mid) {
            merge[it1 + it2] = arr[l + it1];
            it1 += 1;
        }
        while (mid + it2 < r) {
            merge[it1 + it2] = arr[mid + it2];
            it2 += 1;
        }
        for (int i = 0; i < it1 + it2; i += 1)
            arr[l + i] = merge[i];
    }

    void build(vvs &A) {
        for (auto &acc : A)
            for (int i = 2; i < (int) acc.size(); i += 1) {
                g[acc[i]].push_back(acc[i - 1]);
                g[acc[i - 1]].push_back(acc[i]);
            }
    }

    void dfs(string &email) {
        used.insert(email);
        ans.back().push_back(email);
        for (auto &nextEmail : g[email]) {
            if (!used.count(nextEmail)) {
                dfs(nextEmail);
            }
        }
    }

    vvs accountsMerge(vector<vector<string>> &A) {
        build(A);
        for (auto &acc : A) {
            if (!used.count(acc[1])) {
                ans.push_back({acc[0]});
                dfs(acc[1]);
                sort(1, (int) ans.back().size(), ans.back());
            }
        }
        return ans;
    }

public:
    void work() {
        vvs A = {{"David","Avid0@m.co","David0@m.co","David1@m.co"},{"David","Gvid3@m.co","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"}};
        vvs res = accountsMerge(A);
        cout << "";
    }
};