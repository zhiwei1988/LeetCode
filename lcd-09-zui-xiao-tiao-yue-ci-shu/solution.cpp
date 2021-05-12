class Solution {
public:
    int minJump(vector<int>& jump) {
        vector<int> dp(jump.size(), 0);

        for (int i = jump.size()-1; i >= 0; i--) {
            if (i + jump[i] >= jump.size()) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i+jump[i]] + 1;
            }

            for (int j = i+1; j < jump.size() && dp[j] >= (dp[i]+1); j++) {
                dp[j] = dp[i] + 1;
            }
        }

        return dp[0];
    }
};
