#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class ConsecutiveCharacters {
public:
    int maxPower(string s) {
        int len = (int) s.length(), prevChCode = -1, tmpAns = 0, ans = 0;
        for (int i = 0; i < len; i += 1) {
            int chCode = s[i] - 'a';
            if (prevChCode != chCode) {
                prevChCode = chCode;
                tmpAns = 1;
            } else {
                tmpAns += 1;
            }
            ans = max(ans, tmpAns);
        }
        return ans;
    }

    void work() {
        string s = "hooraaaaaaaaaaay";
        int mp = maxPower(s);
        cout << "res\n";
    }
};