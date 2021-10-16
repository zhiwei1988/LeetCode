class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // sum[i] 表示以 index=i 的元素作为结尾的子序列的和的最大值
        vector<int> sum(nums.size());
        deque<int> q; // 队列里保存sum元素下标，元素值单调递减
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum[i] = nums[i];
            while (!q.empty() && i - q.front() > k) {
                q.pop_front(); // 队列首元素不符合要求
            }

            if (!q.empty()) {
                // sum[i-1] 到 sum[i-k] 代表的子序列都可以将 nums[i] 添加进来
                // 取其中的最大值
                sum[i] += sum[q.front()];
            }

            res = max(res, sum[i]);

            while (!q.empty() && sum[i] >= sum[q.back()]) {
                q.pop_back(); // 保证队列单调递减的性质
            }

            if (sum[i] > 0) {
                q.push_back(i);
            }
        }

        return res;
    }
};
