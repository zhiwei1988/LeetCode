class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> freq(100, 0);
        int len = s.length();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int count = 0; // 子串中包含的字符种类

        while (right < len) {
            if (freq[s[right]-'A'] == 0) {
                count++;
            }

            freq[s[right]-'A']++;
            right++;

            while (count > 2) {
                freq[s[left]-'A']--;
                if (freq[s[left]-'A'] == 0) {
                    count--;
                }

                left++;
            }

            maxLen = max(maxLen, right-left);
        }

        return maxLen;
    }
};
