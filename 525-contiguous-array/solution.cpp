class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                // 此处非常巧妙，经过处理后，问题就变成了和为 0 的最长子数组
                nums[i] = -1;
            }
        }

        unordered_map<int, int> hashMap;
        hashMap[0] = -1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hashMap.count(sum)) {
                res = max(res, i-hashMap[sum]);
            } else {
                hashMap[sum] = i;
            }
        }

        return res;
    }
};
