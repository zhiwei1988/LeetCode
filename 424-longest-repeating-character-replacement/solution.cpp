class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> frequency(26, 0); // 滑动窗口中某个字母出现的频率
        int left = 0;
        int right = 0;
        int maxCount = 0; // 频率最高的字符串出现的频率
        int len = s.length();
        int res = 0;

        if (len < 2) {
            return len;
        }

        while (right < len) {
            frequency[s[right]-'A']++;
            maxCount = max(maxCount, frequency[s[right]-'A']);
            right++;

            if (right - left > maxCount + k) {
                // 如果窗口大小比窗口中出现频率最大的字符个数加上其他k个字符
                // 都转化成该字符后的总数还大时，则不可能是满足条件的子串了，窗口大小需要减小
                frequency[s[left] - 'A']--;
                left++;
            }

            res = max(res, right - left);
        }

        return res;
    }
};
