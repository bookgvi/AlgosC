#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int *suffixArray(string str, int len) {
    int b = 8;
    int p[len], c[len], count[1 << b];
    memset(count, 0, 1 << b * sizeof(int));
    for (int i = 0; i < len; i += 1)
        count[str[i]] += 1;
    for (int i = 1; i < len; i += 1)
        count[i] += count[i - 1];

    // fail
    for (int i = len - 1; i >= 0; i -= 1)
        p[--count[str[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < len; i += 1) {
        if (str[p[i]] != str[p[i - 1]]) classes += 1;
        c[p[i]] = classes - 1;
    }
    int pn[len], cn[len];
    for (int h = 0; (1 << h) < len; h += 1) {
        for (int i = 0; i < len; i += 1) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += len;
        }
        memset(count, 0, 1 << b * sizeof(int));
        for (int i = 0; i < len; i += 1)
            count[c[pn[i]]] += 1;
        for (int i = 1; i < 1 << b; i += 1)
            count[i] += count[i - 1];
        for (int i = len - 1; i >= 0; i -= 1)
            p[--count[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < len; i += 1) {
            int mid1 = (p[i] + (1 << h)) % len, mid2 = (p[i] + (1 << h)) % len;
            if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes += 1;
            cn[p[i]] = classes - 1;
        }
        memcpy(c, cn, len);
    }
    return &p[0];

}

int main() {
    string str = "abracadabra";
    int len = str.length();
    int *p = suffixArray(str, len);
    return 0;
}

