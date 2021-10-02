class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int longest = 0;
        unordered_set<char> chSet;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            auto ret = chSet.insert(ch);
            while (!ret.second) {
                chSet.erase(s[left++]);
                ret = chSet.insert(ch);
            }

            longest = max(longest, i-left+1);
        }

        return longest;
    }
};
