class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int left = 0;
        int right = 0;
        int len = s.length();
        int res = 0;

        while (right < len) {
            cost += fabs(s[right] - t[right]);
            right++;

            while (cost > maxCost) {
                cost -= fabs(s[left] - t[left]);
                left++;
            }

            res = max(res, right-left);
        }

        return res;
    }
};
