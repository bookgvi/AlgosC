#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/basic-calculator-ii/submissions/
 * */
class BasicCalculatorII {
public:
    int calculate(string s) {
        int res = 0;
        vector<int> nums;
        int number = 0;
        char op = '+';
        for (int i = 0, len = (int) s.length(); i < len; i += 1) {
            if (isdigit(s[i])) {
                number = (number * 10) + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && !iswspace(s[i])) || i == len - 1) {
                if (op == '-') {
                    nums.push_back(-number);
                } else if (op == '+') {
                    nums.push_back(number);
                } else if (op == '/') {
                    int prev = nums.back(); nums.pop_back();
                    nums.push_back(prev / number);
                } else if (op == '*') {
                    int prev = nums.back(); nums.pop_back();
                    nums.push_back(prev * number);
                }
                number = 0;
                op = s[i];
            }
        }
        for (int i = 0, len = (int) nums.size(); i < len; i += 1)
            res += nums[i];
        return res;
    }

    void work() {
        string s = "60";
        int res = calculate(s);
        cout << "res";
    }
};