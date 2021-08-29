class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                }
                
                if (st.empty()) {
                    st.push(i);
                } else {
                    int len = i - st.top();
                    res = max(res, len);
                }
                               
            } else {
                st.push(i);
            }
        }
        
        return res;
    }

};
