class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        std::sort(begin(stones), end(stones)); // 先对石头的位置进行排序
        int n = stones.size();
        int maxStep = max(stones[n-1] - stones[1] - n + 2, stones[n-2] - stones[0] - n + 2);
        int minStep = INT_MAX;

        int left = 0;
        int right = 0;
        while (left < n) {
            if (right + 1 < n && stones[right] - stones[left] < n) {
                right++;
            } else {
                if (stones[right] - stones[left] >= n) {
                    // left 到 right 之间能容难的石子已经超过了 n 个
                    right--;
                }

                // 刚好能容纳 n 个石子
                if (right-left+1 == n-1 && stones[right]-stones[left]+1 == n-1) {
                    minStep = min(minStep, 2); // 遇到了前 n-1 个石子已经连续的情况
                } else {
                    // right-left+1 表示该区间内已经存在多少个石子
                    minStep = min(minStep, n - (right-left + 1));
                }

                if (right == n-1 && stones[right] - stones[left] < n) {
                    break;
                }

                left++;
            }
        }
        return vector<int>{minStep, maxStep};
    }
};
