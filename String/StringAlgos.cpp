#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class StringAlgos {
private:
    string str = "aabcaabaac";

    void displayArr(vi arr) {
        for (auto elt : arr)
            printf("%d ", elt);
        cout << "\n";
    }

    vi zFunc(string str) {
        int len = (int) str.size();
        vi z(len, 0);
        for (int i = 1, l = 0, r = 0; i < len; i += 1) {
            if (i <= r) z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < len && str[i + z[i]] == str[z[i]]) z[i] += 1;
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    vi piFunc(string str) {
        int len = (int) str.size();
        vi pi(len, 0);
        for (int i = 0; i < len; i += 1)
            for (int j = 0; j <= i; j += 1) {
                string ss1 = str.substr(0, j);
                string ss2 = str.substr(i - j + 1, j);
                if (ss1 == ss2) pi[i] = j;
            }
        return pi;
    }

    vi piFuncExt(string str) {
        int len = (int) str.size();
        vi pi(len, 0);
        for (int i = 1; i < len; i += 1) {
            int j = pi[i - 1];
            while(j > 0 && str[i] != str[j]) j = pi[j - 1];
            if (str[i] == str[j]) pi[i] = j + 1;
        }
        return pi;
    }

    vi manacher(string str) {
        int len = (int) str.size();
        vi m(len, 0);
        for (int i = 1, l = 0, r = 0; i < len; i += 1) {
            if (i < r) m[i] = min(m[l - i + r], r - i + 1);
            while(i - m[i] >= 0 && i + m[i] < len && str[i - m[i]] == str[i + m[i]]) m[i] += 1;
            if (i + m[i] - 1 > r) {
                l = i - m[i] + 1;
                r = i + m[i] - 1;
            }
        }
        return m;
    }

public:
    void display() {
        cout << str << "\n";
        vi z = zFunc(str);
        vi pi = piFunc(str);
        vi piExt = piFuncExt(str);
        vi m = manacher(str);
        displayArr(z);
        displayArr(pi);
        displayArr(piExt);
        displayArr(m);
    }

};