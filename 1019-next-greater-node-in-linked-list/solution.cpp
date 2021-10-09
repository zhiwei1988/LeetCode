class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> help;
        ListNode* node = head;
        while (node) {
            help.push_back(node->val);
            node = node->next;
        }

        stack<int> s;
        vector<int> result(help.size(), 0);
        for (int i = help.size() - 1; i >= 0; i--) {
            while (!s.empty() && help[i] >= s.top()) {
                s.pop();
            }

            if (!s.empty()) {
                result[i] = s.top();
            }
            
            s.push(help[i]);
        }
        
        return result;
    }
};
