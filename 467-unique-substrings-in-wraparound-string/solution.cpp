class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> maxLens(26, 0); //  以 c 结尾的满足条件的最大子数组个数
        // 因为满足条件子数组起字符是连续且递增的，因此以 c 结尾的个数较大的子数组肯定
        // 包含了个数较小的子数组

        int w = 1;
        int c = p[0] - 'a';
        maxLens[c] = max(maxLens[c], w);
        for (int i = 1; i < p.length(); i++) {
            int diff = p[i] - p[i-1];
            if (diff == 1 || diff == -25) {
                w++;
            } else {
                w = 1;
            }

            int c = p[i] - 'a';
            maxLens[c] = max(maxLens[c], w);
        }

        return accumulate(maxLens.begin(), maxLens.end(), 0);
    }
};