class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n1 = stamp.length();
        int n2 = target.length();
        vector<bool> done(n2, false); // 用于存放已经是 '?' 的位置
        queue<int> q; // 用于存放新增的 '?'
        unordered_map<int, window> windows; // first - 窗口起始位置， second - 窗口信息
        stack<int> s;
        if (stamp[0] != target[0] || stamp[n1-1] != target[n2-1]) {
            return vector<int>();
        }

        if (n2 < n1) {
            return vector<int>();
        }

        for (int i = 0; i <= n2 - n1; i++) {
            window win;
            for (int j = 0; j < n1; j++) {
                if (target[i+j] == stamp[j]) {
                    win.match.insert(i+j);
                } else {
                    win.unmatch.insert(i+j);
                }
            }

            if (win.unmatch.empty()) {
                for (auto pos : win.match) {
                    if (done[pos] == false) {
                        done[pos] = true; // 将对应的位置设置成 '?'
                        q.push(pos);
                    }
                }

                s.push(i); // 记录盖戳的位置
            } else {
                windows[i] = win;
            }
        }

        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            for (int i = max(0, pos-n1); i <= min(n2-n1, pos); i++) {
                if (windows.count(i) && windows[i].unmatch.count(pos)) {
                    windows[i].unmatch.erase(pos);
                    if (windows[i].unmatch.empty()) { // 可以盖戳了
                        for (auto pos1 : windows[i].match) {
                            if (done[pos1] == false) {
                                done[pos1] = true; // 将对应的位置设置成 '?'
                                q.push(pos1);
                            }
                        }

                        s.push(i);
                        windows.erase(i);
                    }
                }
            }
        }

        for (int i = 0; i < n2; i++) {
            if (done[i] == false) {
                return vector<int>(); // 此时还存在没有变成 '?' 的位置，则说明没有正确的答案
            }
        }

        if (s.size() > 10 * n2) {
            return vector<int>();
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }

private:
    struct window {
        unordered_set<int> match; // 记录窗口中 与 stamp 中对应位置字符相等的下标
        unordered_set<int> unmatch; // 记录窗口中 与 stamp 中对应位置字符不相等的下标
    };
};
