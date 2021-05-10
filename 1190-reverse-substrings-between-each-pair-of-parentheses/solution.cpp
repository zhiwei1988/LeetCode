class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> _stack;
        string result;
        for (int i = 0; i < s.length(); i++) {
            if (_stack.empty() && s[i] != '(') {
                // 处理最外层括号以外的字符，如 "a(cdef)d" 中的 'a' 和 'b'
                result += s[i];
            } else if (s[i] != ')') {
                _stack.push(s[i]);
            } else {
                // 碰到右括号后，将栈中的元素挨个出栈，之道碰到左括号
                string cur;
                while (_stack.top() != '(') {
                    cur += _stack.top();
                    _stack.pop();
                }

                _stack.pop(); // 弹出 '('

                if (_stack.empty()) {
                    // 如果此时栈已经为空，则可以将子字符串添加到结果中
                    result += cur;
                } else {
                    // 否则子字符串需要继续入栈
                    for (auto c : cur) {
                        _stack.push(c);
                    }
                }
            }
        }

        return result;
    }
};
