#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class ReorderList {
private:
    ListNode *arrToList(vi &arr) {
        if ((int) arr.size() < 2) return new ListNode(arr[0]);
        auto head = new ListNode(arr[0], new ListNode(arr[1]));
        auto *next = head->next;
        int n = (int) arr.size();
        for (int i = 2; i < n; i += 1) {
            next->next = new ListNode(arr[i]);
            next = next->next;
        }
        return head;
    }

    vi listToArr(ListNode *head) {
        vi arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        return arr;
    }

public:
    void reorderList(ListNode *head) {
        vi arr = listToArr(head), prep;
        if ((int) arr.size() > 1) {
            for (int i = 0, end = (int) arr.size() - 1; i <= end >> 1; i += 1) {
                int tmp = end - i;
                prep.push_back(arr[i]);
                if (tmp != i) prep.push_back(arr[tmp]);
            }
            head->val = prep[0];
            head->next->val = prep[1];
            auto *next = head->next;
            int n = (int) prep.size();
            for (int i = 2; i < n; i += 1) {
                next->next = new ListNode(prep[i]);
                next = next->next;
            }
        }
    }

    void work() {
        vi arr = {1,2,3,4,5};
        ListNode *head = arrToList(arr);
        reorderList(head);
        cout << "res\n";
    }
};