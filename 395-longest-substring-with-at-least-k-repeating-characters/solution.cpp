class Solution {
public:
    int longestSubstring(string s, int k) {
        for (int i = 1; i <= 26; i++) {
            slidWindow(s, k, i);
        }
        return longest;
    }

    /**
     * 
     * @param s 
     * @param k 窗口中每种字符至少包含 k 个
     * @param u 窗口中最多包含 u 种不同的字符
     */
    void slidWindow(string s, int k, int u)
    {
        unordered_map<char, int> chSet;
        int valid = 0;
        int left = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            chSet[ch]++;
            if (chSet[ch] == k) {
                valid++;
            }
            while (chSet.size() > u) {
                char ch1 = s[left];
                left++;
                if (chSet[ch1] == k) {
                    valid--;
                }
                chSet[ch1]--;
                if (chSet[ch1] == 0) {
                    chSet.erase(ch1);
                }
            }
            if (chSet.size() == u && valid == u) {
                int num = i - left + 1;
                longest = max(longest, num);
            }
        }
    }
    int longest = 0;
};
