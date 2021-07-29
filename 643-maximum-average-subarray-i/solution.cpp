class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum = sum + nums[i] - nums[i-k]; // 长度固定，加一个数就要减去一个数
            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};