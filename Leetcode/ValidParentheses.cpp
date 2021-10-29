#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef unordered_map<int, int> uom;

class ValidateParentheness {
public:
    bool isValid(string s) {
        int lenS = s.length();
        vi stack;
        uom t1;
        t1['}'] = '{';
        t1[']'] = '[';
        t1[')'] = '(';
        if (lenS & 1) return false;
        if (!(s[0] ^ '}') || !(s[0] ^ ']') || !(s[0] ^ ')')) return false;
        for (int i = 0; i < lenS; i += 1) {
            if (stack.empty()) stack.push_back(s[i]);
            else {
                int chInMap = t1.count(s[i]);
                if (!chInMap) stack.push_back(s[i]); // если это открывающий символ, то пушим в стэк
                else {
                    if (stack.back() ^  t1.at(s[i])) return false;
                    else stack.pop_back();
                }
            }
        }
        return stack.empty();
    }
};
