#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

class LexicographicSort {
public:
    static int comparator(string &str1, string &str2) {
        int len1 = (int) str1.length(), len2 = (int) str2.length();
        int len = min(len1, len2);
        for (int i = 0; i < len; i += 1)
            if (str1[i] != str2[i]) return str1[i] - str2[i];
        return len1 - len2;
    }

    static vs sort(vs &arr) {
        return mergeSort(arr);
    }

    static vs mergeSort(vs arr) {
        for (int i = 1, len = (int) arr.size(); i < len; i <<= 1)
            for (int j = 0; j < len - i; j += i << 1)
                merge(j, i + j, min(len, j + (i << 1)), arr);
        return arr;
    }

    static void merge(int l, int mid, int r, vs &arr) {
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

    static int getSet(string &str) {
        int set = 0;
        for (int i = 0, len = (int) str.length(); i < len; i += 1)
            set |= (1 << (str[i] - 'a'));
        return set;
    }

    static string getStrFromSet(int set) {
        string res = "";
        for (int i = 0; i < 32; i += 1)
            if (set & (1 << i)) res += i + 'a';
        return res;
    }

    static vs generateSubStr(string &str, int n) {
        vs res;
        int set = getSet(str);
        int b = 0;
        do {
            string s = getStrFromSet(b);
            if ((int) s.length() == n) res.push_back(s);
        } while ((b = (b - set) & set));
        return res;
    }

    void work() {
        int n = 4;
        string str = "czwqabflv";
        vs res = generateSubStr(str, n);
        res = sort(res);
    }
};
