class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) { // 枚举子矩阵上边界
            vector<int> subarray(n);
            for (int j = i; j < m; j++) { // 枚举子矩阵下边界
                for (int z = 0; z < n; z++) {
                    subarray[z] += matrix[j][z]; // 计算边界内每一列元素的和
                }
                res += subarraySum(subarray, target);
            }
        }
        return res;
    }
private:
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
