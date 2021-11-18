#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

class LexicographicSort {
public:
    int comparator(string s1, string s2) {
        int s1len = (int) s1.size(), s2len = (int) s2.size(), minLen = min(s1len, s2len);
        for (int i = 0; i < minLen; i += 1)
            if (s1[i] - s2[i] != 0) return s1[i] - s2[i];
        return s1len - s2len;
    }

    vs insertSort(vs &arr) {
        for (int i = 0, len = arr.size(); i < len; i += 1)
            for (int j = i; j > 0 && comparator(arr[j - 1], arr[j]) > 0; j -= 1)
                swap(arr[j - 1], arr[j]);
        return arr;
    }

    vs mergeSort(vs &arr) {
        for (int i = 1, len = arr.size(); i < len; i <<= 1)
            for (int j = 0; j < len - i; j += i << 1)
                merge(j, j + i, min(len, j + (i << 1)), arr);
        return arr;
    }

    void merge(int l, int mid, int r, vs &arr) {
        int it1 = 0, it2 = 0;
        vs merge(r - l);
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

    vs sort(vs &arr) {
        return arr.size() < 7 ? insertSort(arr) : mergeSort(arr);
    }

    int initSet(string &str) {
        int set = 0;
        for (int i = 0, len = str.size(); i < len; i += 1)
            set |= (1 << (str[i] - 'a' + 1));
        return set;
    }

    string getStr(int set) {
        string str;
        for (int i = 0; i < 32; i += 1) {
            if (set & (1 << i)) str += (i + 'a' - 1);
        }
        return str;
    }

    vs generateSubStr(string &str, int len) {
        vs ss;
        int set = initSet(str);
        int b = 0;
        do {
            string tmpS = getStr(b);
            if (tmpS.size() == len) ss.push_back(tmpS);
        } while (b = (b - set) & set);
        return ss;
    }

    void work() {
        int n = 4;
        string str = "cabflwqxzshj";
        vs res = generateSubStr(str, n);
        res = sort(res);
    }
};
