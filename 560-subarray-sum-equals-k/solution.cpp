class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap; // 记录各个 sum 值在之前出现的次数
        // sum[i] - sum[j] = k，则 j+1 到 i 之间子数组之和为 k
        int pre = 0;
        int res = 0;
        sumMap[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (sumMap.count(pre-k) != 0) {
                res += sumMap[pre-k];
            }
            sumMap[pre]++;
        }

        return res;
    }
};
