class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        vector<int> frequence(128, 0);
        int diff = 0;
        int maxLen = 0;
        while (right < s.length()) {
            char c = s[right];
            if (frequence[c] == 0) {
                diff++;
            }

            frequence[c]++;

            while (diff > k) {
                char c1 = s[left];
                frequence[c1]--;
                if (frequence[c1] == 0) {
                    diff--;
                }
                left++;
            }

            int len = right - left + 1;
            maxLen = max(maxLen, len);
            right++;
        }

        return maxLen;
    }
};