class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] 表示当总金额为 i 时所需的最小硬币个数
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                int coin = coins[j];
                if (i - coin < 0) {
                    continue;
                } else {
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }

        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};
