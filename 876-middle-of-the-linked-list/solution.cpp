/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while (slow->next != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != nullptr) {
                fast = fast->next;
            } else {
                break;
            }
        }

        return slow;
    }
};