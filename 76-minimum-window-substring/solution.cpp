class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        
        for (auto c : t) need[c]++;
        
        int start = 0;
        int len = INT_MAX;
        int left = 0;
        int right = 0;
        int valid = 0;

        while (right < s.length()) {
            auto c1 = s[right];
            right++;

            if (0 != need.count(c1)) {
                window[c1]++;
                if (window[c1] == need[c1]) valid++;
            }

            while (valid == need.size()) {
                if (len > right - left) {
                    len = right - left;
                    start = left;
                }

                auto c2 = s[left];
                left++; // 缩小窗口
                if(0 != need.count(c2)) {
                    if (window[c2] == need[c2]) valid--;
                    window[c2]--;
                }
            }
        }

        if (len == INT_MAX) return "";
        return s.substr(start, len);
    }
};
