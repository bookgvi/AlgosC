#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

class LexicographicSort {
public:
    int comparator(string str1, string str2) {
        int len1 = (int) str1.length(), len2 = (int) str2.length();
        int len = min(len1, len2);
        for (int i = 0; i < len; i += 1) {
            if (str1[i] != str2[i]) return str1[i] - str2[i];
        }
        return len1 - len2;
    }

    vs sort(vs &strList) {
        return strList.size() > 20 ? mergeSort(strList) : insertSort(strList);
    }

    vs mergeSort(vs &arr) {
        for (int i = 1, len = (int) arr.size(); i < len; i <<= 1)
            for (int j = 0; j < len - i; j += i << 1)
                merge(j, i + j, min(len, j + (i << 1)), arr);
        return arr;
    }

    void merge(int l, int mid, int r, vs &arr) {
        int it1 = 0, it2 = 0;
        vs merge(r - l, "");
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

    vs insertSort(vs &arr) {
        for (int i = 0, len = (int) arr.size(); i < len; i += 1)
            for (int j = i; j > 0 && comparator(arr[j - 1], arr[j]) > 0; j -= 1)
                swap(arr[j - 1], arr[j]);
        return arr;
    }

    int getSet(string &str) {
        int set = 0;
        for (int i = 0, len = (int) str.length(); i < len; i += 1)
            set |= (1 << (str[i] - 'a' + 1));
        return set;
    }

    string getSubStrFromSet(int set) {
        string str = "";
        for (int i = 0; i < 32; i += 1)
            if (set & (1 << i)) str += i + 'a' - 1;
        return str;
    }

    vs generateSubStr(string str, int len) {
        vs res;
        int set = getSet(str);
        int b = 0;
        do {
            string ss = getSubStrFromSet(b);
            if (ss.length() == len) res.push_back(ss);
        } while ((b = (b - set) & set));
        return res;
    }

    void work() {
        int n = 4;
        string str = "cabflv";
        vs res = generateSubStr(str, n);
        res = sort(res);
    }
};
