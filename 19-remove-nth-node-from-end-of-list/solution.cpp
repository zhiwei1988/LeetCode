/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        for (int i = 0; i < n-1; i++) {
            if (fast != nullptr) fast = fast->next;
        }

        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            fast = fast->next;
            slow = slow->next;
        }

        if (pre != nullptr && slow != nullptr) {
            pre->next = slow->next;
        } else {
            dummy->next = slow->next;
        }

        return dummy->next;
    }
};