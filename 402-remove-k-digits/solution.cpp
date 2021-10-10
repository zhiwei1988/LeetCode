class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> s; // 单调递减栈
        for (int i = 0; i < n; i++) {
            while (!s.empty() && num[i] < s.top() && k > 0) {
                k--;
                s.pop();
            }

            s.push(num[i]);
        }

        while (k > 0 && !s.empty()) {
            k--;
            s.pop(); // 还能移除数字，则先把大的数移除
        }

        bool first = true;
        string temp;
        while (!s.empty()) {
            temp = s.top() + temp;
            s.pop();
        }

        auto pos = temp.find_first_not_of('0'); // 去除前导零
        string result;
        if (pos != string::npos) {
            result = temp.substr(pos);
        }

        return result.empty() ? "0" : result;
    }
};
