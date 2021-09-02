class Solution {
public:
    string longestDupSubstring(string s) {
        int len = s.length();
        int left = 1;
        int right = len;
        int start = -1; // 重复字符串的起始位置
        int substrLen = 0;
        int temp = -1;
        nums.resize(len);
        for (int i = 0; i < len; i++) {
            nums[i] = s[i] - 'a';
        }

        // 假设 len2 > len1，如果存在 len2 的重复子串，则肯定存在 len1 的重复子串
        // 因此可以采用二分查找
        while (left < right) {
            int mid = left + (right - left) / 2;
            temp = HaveDuplicateSubStr(mid);
            if (temp != -1) {
                left = mid + 1; // 查找更长的子串
                start = temp;
                substrLen = mid;
            } else {
                right = mid; // 查找更短的子串
            }
        }

        
        if (left != len) {
            temp = HaveDuplicateSubStr(left); 
            if (temp != -1) {
                start = temp;
                substrLen = left;
            }
        }

        return start == -1 ? "" : s.substr(start, substrLen);
    }

private:
    //查看是否是真重复子串还是因为发生哈希碰撞而导致哈希值相同
    bool check(pair<int, int> &a, pair<int, int> b) {
        for (int i = a.first, j = b.first; i <= a.second && j <= b.second; ++i, ++j) {
            if (nums[i] != nums[j]) {
                return false;
            }
        }
        return true;
    }

    // 判断 s 中是否存在长度为 len 的重复子串
    int HaveDuplicateSubStr(int len)
    {
        unordered_map<long, pair<int, int>> encodes;
        int start = 0;

        long h = 0;
        // Rabin-Karp 字符串编码
        for (int i = 0; i < len; i++) {
            h = (h * base + nums[i]) % mod;
        }

        encodes[h] = make_pair(0, len-1);

        long baseL = 1; // baseL = base^L;
        for (int i = 1; i <= len; i++) {
            baseL = (baseL * base) % mod;
        }

        for (int i = len; i < nums.size(); i++) {
            start++;
            h = (h * base - nums[start-1] * baseL % mod + mod) % mod; // 此处 + mod 是防止负数的出现
            h = (h + nums[i])  % mod;
            if (encodes.count(h) != 0 && check(encodes[h], make_pair(start, start+len-1))) {
                return start;
            }
            encodes[h] = make_pair(start, start+len-1);
        }

        return -1;
    }

    vector<int> nums;
    int mod = INT_MAX;
    int base = 26;
};
