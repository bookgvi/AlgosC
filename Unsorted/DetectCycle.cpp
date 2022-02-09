#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class DetectCycle {
private:
    int lambda = -1, // cycle length
            mu = -1; // in this index cycle is begin

    static ListNode *build(vi &arr, int cycleStart) {
        ListNode *head = new ListNode(arr[0]), *next = nullptr, *csNode = nullptr;
        next = head;
        for (int i = 1; i < (int) arr.size(); i += 1) {
            next->next = new ListNode(arr[i]);
            if (arr[i] == cycleStart) csNode = next->next;
            next = next->next;
        }
        next->next = csNode;
        return head;
    }

    // Brent detect cycle algo
    ListNode *detectCycleB(ListNode *head) {
        ListNode *fast = head->next, *slow = nullptr;
        int pow = 1;
        lambda = pow;
        while (fast != nullptr && slow != fast) {
            if (pow == lambda) {
                pow <<= 1;
                lambda = 0;
                slow = fast;
            }
            fast = fast->next;
            lambda += 1;
        }
        if (slow == fast) {
            slow = head, fast = head;
            for (int i = 0; i < lambda; i += 1)
                fast = fast->next;
            mu = 0;
            while (slow != fast) {
                fast = fast->next;
                slow = slow->next;
                mu += 1;
            }
        } else {
            lambda = -1;
        }
        return fast;
    }

public:
    void work() {
        vi arr = {1, 2, 3, 4, 5, 6};
        ListNode *head = build(arr, 3);
        ListNode *csNode = detectCycleB(head);
        cout << "fin\n";
    }
};