class Solution {
public:
    string smallestSubsequence(string s) {
        string result;
        unordered_map<char, int> lastPos; // 记录字符最后出现的位置
        unordered_map<char, int> used; // 字符是否已经在栈中
        stack<char> st; // 单调递减栈

        for (int i = 0; i < s.size(); i++) {
            lastPos[s[i]] = i;
            used[s[i]] = false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (used[s[i]]) continue; // 保证字符唯一性
            // 如果栈顶元素比当前元素大（字典序），且后面还有栈顶元素同样的字符，则挨个将栈顶元素出栈
            // 知道栈顶元素比当前元素小，然后将当前元素入栈（保证最小字典序），如果后面没有相同元素了，就不出栈（保证完整性）
            while (!st.empty() && s[i] < st.top() && lastPos[st.top()] > i) {
                used[st.top()] = false;
                st.pop();
            }

            st.push(s[i]);
            used[s[i]] = true;
        }

        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
