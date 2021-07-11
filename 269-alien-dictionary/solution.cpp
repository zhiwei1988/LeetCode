class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<int> indu(26, 0);
        unordered_map<char, unordered_set<char>> outdu;

        // 初始化邻接表
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                outdu[words[i][j]] = unordered_set<char>();
            }
        }
        
        // 创建邻接表
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            auto minLen = min(s1.length(), s2.length());
            for (int j = 0; j < minLen; j++) {
                if (s1[j] != s2[j]) {
                    if (!outdu[s1[j]].count(s2[j])) {
                        indu[s2[j]-'a']++;
                        outdu[s1[j]].emplace(s2[j]);
                    }
                    break;
                }

                // 按字典排序不可能出现 "abc" 在 "ab" 前面的情况
                if (j == (minLen - 1) && (s1.length() > s2.length())) {
                    return "";
                } 
            }
        }

        queue<char> q;
        for (auto m : outdu) {
            if (indu[m.first-'a'] == 0) {
                q.emplace(m.first);
            }
        }

        string res = "";
        while (!q.empty()) {
            auto p = q.front();
            res += p;
            q.pop();
            for (auto m : outdu[p]) {
                indu[m-'a']--;
                if (indu[m-'a'] == 0) {
                    q.emplace(m);
                }
            }    
        }

        if (res.length() != outdu.size()) {
            return "";
        }

        return res;
    }
};