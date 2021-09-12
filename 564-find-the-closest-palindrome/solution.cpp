class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        long num = stol(n);

        if (num < 10) {
            return to_string(num-1); // 此时 +1 和 -1 差的绝对值是一样的，取最小的那个
        } else if (num == pow(10, len-1)) {
            return to_string(num-1); // 10 -> 9 10000 -> 9999 的场景
        } else if ((num-1) == pow(10, len-1)) {
            return to_string(num-2); // 11 -> 9 10001 -> 9999 的场景
        } else if ((num+1) == pow(10, len-1)) {
            return to_string(num+2); // 9999 -> 10001 的场景
        }

        // 其他场景，是把前面一半拿出来，然后倒过来补全即可
        long halfNum = stol(n.substr(0, (len + 1) / 2));
        int minDiff = INT_MAX;
        string res;
        for (auto incre : {-1, 0, 1}) {
            auto halStr = to_string(halfNum + incre);
            string reverse(halStr.rbegin(), halStr.rend()); 
            // 奇数个字符时，中间字符包含在 reverse 中
            string cur = halStr.substr(0, len / 2) + reverse;
            long palindromic = stol(cur);
            int diff = abs(palindromic - num);
            if (palindromic != num && diff < minDiff) {
                res = cur;
                minDiff = diff;
            }
        }

        return res;
    }
};
