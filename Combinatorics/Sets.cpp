#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class Sets {
private:
    string nextSet(string s) {
        int len = s.length(), i;
        for (i = len - 2; i >= 0; i -= 1) {
            if (s[i] == '0' && s[i + 1] == '1') break;
        }
        int ones = 0;
        for (int j = i; j < len; j += 1)
            ones = s[j] == '1' ? ones + 1 : ones;
        s[i] = '1';
        for (int j = i + 1; j < len - ones + 1; j += 1)
            s[j] = '0';
        for (int j = len - ones + 1; j < len; j += 1)
            s[j] = '1';
        return s;
    }

    string nextSet1(string s) {
        int len = s.length(), i;
        for (i = len - 2; i >= 0; i -= 1)
            if (s[i] == '0' && s[i + 1] == '1') break;
        s[i] = '1';
        int ones = 0;
        for (int j = i + 1; j < len; j += 1)
            ones = s[j] == '1' ? ones + 1 : ones;
        for (int j = i + 1; j < len - ones + 1; j += 1)
            s[j] = '0';
        for (int j = len - ones + 1; j < len; j += 1)
            s[j] = '1';
        return s;
    }

public:
    void work() {
        string s = "001011";
        cout << s << "\n";
        for (int i = 1; i < 16; i += 1) {
            s = nextSet(s);
            cout << s << "\n";
        }
    }
};