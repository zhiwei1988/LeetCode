class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int left = 0;
        int right = 0;
        int subStrNum = 0;
        if (k > s.length()) {
            return 0;
        }

        vector<int> frequence(26, 0);
        int charCount = 0;
        while (right < s.length()) {
            char c = s[right];

            frequence[c-'a']++;
            charCount++;
            if (frequence[c-'a'] == 2) {
                while (left < right) {
                    char c1 = s[left];
                    left++;
                    charCount--;
                    frequence[c1-'a']--;
                    if (c1 == c) {
                        break;
                    }
                }
            }

            if (charCount == k) {
                frequence[s[left]-'a']--;
                subStrNum++;
                left++;
                charCount--;
                
            }

            right++;
        }

        return subStrNum;
    }
};