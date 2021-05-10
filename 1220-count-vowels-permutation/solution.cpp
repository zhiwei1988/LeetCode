class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        vector<vector<int>> charIndexs(5, vector<int>{});
        charIndexs[0] = vector<int> {1};
        charIndexs[1] = vector<int> {0, 2};
        charIndexs[2] = vector<int> {0, 1, 3, 4};
        charIndexs[3] = vector<int> {2, 4};
        charIndexs[4] = vector<int> {0};
        
        for (int i = 0; i < 5; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                for (int z = 0; z < charIndexs[j].size(); z++) {
                    int index = charIndexs[j][z];
                    dp[i][j] += (dp[i-1][index] % 1000000007);
                    dp[i][j] %= 1000000007;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += dp[n][i];
            sum %= 1000000007;
        }
        return sum;
    }
};
