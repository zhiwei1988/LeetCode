class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) dp[i][0] = i; // word1 经过 i 步删除与 word2 一致
        for (int i = 1; i <= n; i++) dp[0][i] = i; // word1 经过 i 步添加与 word2 一致

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]; // 跳过
                } else {
                    dp[i][j] = min((dp[i-1][j] + 1), // 删
                                   (dp[i][j-1] + 1), // 增
                                   (dp[i-1][j-1] + 1)); // 替换
                }
            }
        }

        return dp[m][n];
    }
private:
    int min(int a, int b, int c) {
        int res = INT_MAX;
        if (a < res) res = a;
        if (b < res) res = b;
        if (c < res) res = c;
        return res;
    }
};
