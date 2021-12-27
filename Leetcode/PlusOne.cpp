#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

/*
 * https://leetcode.com/problems/plus-one/submissions/
 * */
class PlusOne {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = (int) digits.size();
        digits[len - 1] += 1;
        for (int i = len - 1, carry = 0; i >= 0 || carry != 0; i -= 1) {
            if(i < 0) {
                vi tmp = vi(len + 1, 0);
                for (int i = len - 1; i >= 0; i -= 1)
                    tmp[i + 1] = digits[i];
                digits = tmp;
                i += 1;
            }
            digits[i] += carry;
            carry = digits[i] > 9 ? 1 : 0;
            if (carry) digits[i] -= 10;
        }
        return digits;
    }

    void work() {
        vi arr = {9, 9};
        vi res = plusOne(arr);
        cout << "res";
    }
};