class Solution {
public:
    int numberOfSubstrings(string s) {
        int subArrays = 0;
        int count = 0;
        vector<int> freq(3, 0);

        int left = 0;
        int right = 0;
        while (right < s.length()) {
            char c = s[right];
            if (freq[c-'a'] == 0) {
                count++;
            }

            freq[c-'a']++;

            while (count >= 3) {
                // [left, right] 满足条件，则 right 之后的子数组都满足条件
                subArrays += s.length() - right;
                char c = s[left];
                left++;
                freq[c-'a']--;
                if (freq[c-'a'] == 0) {
                    count--;
                }
            }

            right++;;
        }

        return subArrays;
    }
};