class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (i < m) {
            while (i < m && j < n) { // 先找到包含 s2 所有元素的子串
                if (s1[i] == s2[j]) {
                    j++;
                }

                i++;
            }

            if (j < n) {
                break; // 以 i 开始的子串已经无法包含子序列 s2
            }

            int left = i-1;
            int right = i;
            j--;
            while (left >= 0 && j >= 0) {
                if (s1[left] == s2[j]) { // 逆向窗口以满足子串最短
                    j--;
                }
                left--;
            }

            left++;

            if (right - left < minLen) {
                start = left;
                minLen = right - left;
            }

            i = left + 1;
            j = 0;
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s1.substr(start, minLen);
    }
};