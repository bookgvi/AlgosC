#include <bits/stdc++.h>
using namespace std;

int _SuffixArraymain() {
    char * str = "abracadabra";

    unsigned int startTime = clock();
    int maxlen = 11, b = 8;
    int p[maxlen], c[maxlen], count[1 << b];
    memset(count, 0, (1 << b) * sizeof(int));
    for (int i = 0; i < maxlen; i += 1)
        count[str[i]] += 1;
    for (int i = 1; i < 1 << b; i += 1)
        count[i] += count[i - 1];
    for (int i = maxlen - 1; i >= 0; i -= 1)
        p[--count[str[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < maxlen; i += 1) {
        if (str[p[i]] != str[p[i - 1]]) classes += 1;
        c[p[i]] = classes - 1;
    }
    int pn[maxlen], cn[maxlen];
    for (int h = 0; (1 << h) < maxlen; h += 1) {
        for (int i = 0; i < maxlen; i += 1) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += maxlen;
        }
        memset(count, 0, (1 << b) * sizeof(int));
        for (int i = 0; i < maxlen; i += 1)
            count[c[pn[i]]] += 1;
        for (int i = 1; i < 1 << b; i += 1)
            count[i] += count[i - 1];
        for (int i = maxlen - 1; i >= 0; i -= 1)
            p[--count[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < maxlen; i += 1) {
            int mid1 = (p[i] + (1 << h)) % maxlen, mid2 = (p[i - 1] + (1 << h)) % maxlen;
            if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes += 1;
            cn[p[i]] = classes - 1;
        }
        memcpy(c, cn, maxlen * sizeof(int));
    }
    unsigned int endTime = clock();

    printf("%.7f\n", (endTime - startTime) / (double) CLOCKS_PER_SEC);

    for (int i = 0; i < maxlen; i += 1) {
        for (int j = p[i]; j < maxlen; j += 1)
            cout << str[j];
        cout << "\n";
    }

    cout << "\n";
}
