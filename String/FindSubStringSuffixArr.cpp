#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class FindSubStringSuffixArr {
private:
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
        vi pn(len, 0), cn(len, 0);
        for (int h = 0; 1 << h < len; h += 1) {
            for (int i = 0; i < len; i += 1) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0) pn[i] += len;
            }
            count = vi(1 << b, 0);
            for (int i = 0; i < len; i += 1)
                count[c[pn[i]]] += 1;
            for (int i = 1; i < 1 << b; i += 1)
                count[i] += count[i - 1];
            for (int i = len - 1; i >= 0; i -= 1)
                p[--count[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < len; i += 1) {
                int mid1 = (p[i] - (1 << h)) % len, mid2 = (p[i - 1] - (1 << h)) % len;
                if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes += 1;
                cn[p[i]] = classes - 1;
            }
            for (int i = 0; i < len; i += 1)
                c[i] = cn[i];
        }
        return p;
    }

    int binSearchL(int chCode, vi &arr, int off, string &str) {
        int len = (int) arr.size(), k = len - 1;
        for (int i = len >> 1; i > 0; i >>= 1)
            while (k - i >= 0
                   && off < str.substr(arr[k - i]).length()
                   && str.substr(arr[k - i])[off] >= chCode)
                k -= i;
        if (off < str.substr(arr[k]).length() && str.substr(arr[k])[off] == chCode) return k;
        return -1;
    }

    int binSearchR(int chCode, vi &arr, int off, string &str) {
        int len = (int) arr.size(), k = 0;
        for (int i = len >> 1; i > 0; i >>= 1)
            while (k + i < len
                   && off < str.substr(arr[k + i]).length()
                   && str.substr(arr[k + i])[off] <= chCode)
                k += i;
        if (off < str.substr(arr[k]).length() && str.substr(arr[k])[off] == chCode) return k;
        return -1;
    }

    vi searchSubStr(string &str, string &ss) {
        vi indexes;
        vi p = suffixArray(str);
        for (int i = 0, lenSS = (int) ss.length(); i < lenSS; i += 1) {
            int l = binSearchL(ss[i], p, i, str);
            if (l == -1) {
                cout << "not found..." << "\n";
                return {};
            }
            int r = binSearchR(ss[i], p, i, str);
            vi tmp(p.size());
            for (int j = 0, len = (int) p.size(); j < len; j += 1)
                tmp[j] = p[j];
            p = vi(r - l + 1, 0);
            for (auto j = 0; j != r - l + 1; j += 1)
                p[j] = tmp[l + j];
        }
        return p;
    }

public:
    void work() {
        string str = "abracadabra";
        string ss = "cada";
        string s1 = str.substr(1);
        int s10 = str.substr(1)[(int) s1.length()];
        int s11 = str.substr(1)[(int) s1.length() - 1];
        vi p = searchSubStr(str, ss);
    }
};

