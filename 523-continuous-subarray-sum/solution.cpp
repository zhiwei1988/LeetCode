class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap; // mod 与 position 的映射关系
        int sum = 0;
        hashMap[0] = -1; // 注意，这行很重要，否则类似 [23,2,4,6,6] 7 这种用例过不了
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int mod = sum % k;
            // （sum[i] - sum[j]）% k == 0 根据“同余定理” => sum[i] % k = sum[j] % k
            if (hashMap.count(mod)) {
                if (i - hashMap[mod] > 1) {
                    return true;
                }
            } else {
                hashMap[mod] = i;
            }
        }

        return false;
    }
};
