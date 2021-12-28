#include <bits/stdc++.h>
#include "ListNode.cpp"

using namespace std;

/*
 * https://leetcode.com/problems/middle-of-the-linked-list/
 * */
class MiddleoftheLinkedList {
public:
    ListNode *middleNode(ListNode *head) {
        vector<ListNode *> ans = {head};
        while (ans.back()->next != nullptr) {
            ans.push_back(ans.back()->next);
        }
        return ans[(int) ans.size() >> 1];
    }

    void work() {

    }
};