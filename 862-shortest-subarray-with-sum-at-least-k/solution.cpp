class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // nums 中存在负数，简单的滑动窗口，无法保证从窗口中移除元素后，窗口中
        // 元素和一定变小，需要对 prefix sum 的数组进行滑动窗口
        int n = nums.size();
        int res = n+1; // 结果不可能比 n 大
        vector<int> sum(n+1);
        // sum[i+1] 表示 nums[0, i] 元素之和
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }

        deque<int> q; // 构建单调递增队列
        for (int i = 0; i < n+1; i++) {
            while (!q.empty() && sum[i] <= sum[q.back()]) {
                q.pop_back();
            }

            while (!q.empty() && (sum[i] - sum[q.front()] >= k)) {
                // 因为队列是单调递增的，所以循环内部可以保证，每次循环
                // diff 都在减小
                res = min(res, i-q.front());
                q.pop_front();
            }

            q.push_back(i);
        }

        return res <= n ? res : -1;
    }
};
