#include <bits/stdc++.h>
#include "LinkedList.cpp"

using namespace std;
typedef vector<int> vi;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 *
 *
 * https://leetcode.com/problems/insertion-sort-list/
 */
class InsertionSortList {
private:
    ListNode *build(vi &nums) {
        int len = (int) nums.size();
        if (len < 1) return {};
        auto *head = new ListNode(nums[0]);
        if (len > 1) {
            auto *next = new ListNode(nums[1]);
            head->next = next;
            for (auto i = 2; i < len; i += 1) {
                next->next = new ListNode(nums[i]);
                next = next->next;
            }
        }
        return head;
    }

    ListNode *insertionSortList(ListNode *head) {
        vi arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        int len = (int) arr.size();
        for (int i = 0; i < len; i += 1)
            for (int j = i; j > 0 && arr[j - 1] - arr[j] > 0; j -= 1)
                swap(arr[j - 1], arr[j]);
        return build(arr);
    }

public:
    void work() {
        vi nums = {4, 2, 1, 3};
        ListNode *head = build(nums);
        head = insertionSortList(head);
    }
};