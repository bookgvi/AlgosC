#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/
 * */
class ConvertBinaryNumberinaLinkedListtoInteger {
private:
    vector<int> list;

    void setList(ListNode *h, vector<int> &arr, int i) {
        if (i >= arr.size()) return;
        h->next = new ListNode(arr[i]);
        setList(h->next, arr, i += 1);
    }

    void getList(ListNode *next) {
        list.push_back(next->val);
        if (next->next == nullptr) return;
        getList(next->next);
    }

    long pow(long n, int pow) {
        long res = 1;
        while (pow > 0) {
            if (pow & 1) res *= n;
            n *= n;
            pow >>= 1;
        }
        return res;
    }

public:
    int getDecimalValue(ListNode *head) {
//        getList(head);
        int ans = 0, it = 0;
        ans = head->val << head->val;
        while (head->next != nullptr) {
            head = head->next;
            int t2 = head->val << head->val;
            ans = (t2 + ans) << 1;
        }
//        ans >>= 1;
        return ans;
    }

    void work() {
//        vector<int> vec = {1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
//        vector<int> vec = {1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,1,0};
        vector<int> vec = {1, 1, 1};
        ListNode *h = new ListNode(vec[0]);
        setList(h, vec, 1);
        getDecimalValue(h);
        cout << "res";
    }
};