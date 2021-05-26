class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string sub;
        int maxLen = 0;
        int len = 0;
        int begin = 0;
        int end = 0;
        int size = s.size();
        if (size <= 1) return size;
        for (int i = 1; i < size; ++i) {
            sub = s.substr(begin, end-begin+1);
            len = sub.length();
            auto pos = sub.find(s[i]);
            if (pos == string::npos) {
                // 扩大窗口
                len++;
            } else {
                // 缩小窗口
                begin = begin + pos + 1;
            }

            maxLen = maxLen >= len ? maxLen : len;
            end++; 
        }
        
        return maxLen;
    }
};
