class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (auto c : s1) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;
        while (left < s2.size() && right < s2.size()) {
            auto c1 = s2[right];
            right++;

            if (0 != need.count(c1)) {
                window[c1]++;
                if (window[c1] == need[c1]) {
                    valid++;
                }
            }

            // 当前窗口中的字符数大于等于子串的字符数时就需要窗口大小了
            while (right - left >= s1.length()) {
                if (valid == need.size()) {
                    return true;
                }

                auto c2 = s2[left];
                left++;
                if (0 != need.count(c2)) {
                    if (window[c2] == need[c2]) {
                        valid--;
                    }
                    window[c2]--;
                }
            }
        }
        return false;
    }
};
