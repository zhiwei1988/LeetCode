class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[j] 表示当总金额为 j 时，存在多少个硬币的组合数
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                int coin = coins[i];
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
};
