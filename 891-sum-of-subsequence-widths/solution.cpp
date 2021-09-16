class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long> pow2(n, 1);
        int mod = 1000000007;
        for (int i = 1; i < n; i++) {
            // pow2[i] = 2^i
            pow2[i] = 2 * pow2[i-1] % mod;
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (pow2[i] - pow2[n-i-1]) * nums[i]) % mod;
        }

        return ans;
    }
};
