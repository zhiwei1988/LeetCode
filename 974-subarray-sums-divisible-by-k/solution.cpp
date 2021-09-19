class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap; // 记录各个 mod 在之前出现的次数
        // sum[i] - sum[j] = k，则 j+1 到 i 之间子数组之和为 k
        int pre = 0;
        int res = 0;
        sumMap[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            // （sum[i] - sum[j]）% k == 0 根据“同余定理” => sum[i] % k = sum[j] % k
            int mod = (pre % k + k) % k; // 防止负数的产生
            if (sumMap.count(mod) != 0) {
                res += sumMap[mod];
            }
            sumMap[mod]++;
        }

        return res;
    }
};
