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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        if (head == nullptr) return false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // 如果链表有环，快慢指针肯定会相遇
            if (slow == fast) return true;
        }

        return false;
    }
};