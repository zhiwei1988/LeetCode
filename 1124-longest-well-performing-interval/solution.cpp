class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int maxGoodTime = 0;
        vector<int> preSum(n+1, 0);
        for (int i = 0; i < n; i++) {
            // 计算前缀和
            if (hours[i] > 8) {
                preSum[i+1] = preSum[i] + 1;
            } else {
                preSum[i+1] = preSum[i] - 1;
            }
        }

        stack<int> s;
        s.push(0);
        for (int i = 1; i < n+1; i++) {
            if (preSum[i] < preSum[s.top()]) {
                s.push(i); // 构建单调递减栈
            }
        }

        // preSum[j] - preSum[i] > 0 时 j-i 即表现良好的时间段
        // preSum[j] > preSum[i] 时 j-i 即表现良好的时间段
        for (int i = n; i >= 0; i--) {
            while (!s.empty() && preSum[i] > preSum[s.top()]){
                maxGoodTime = max(maxGoodTime, i - s.top());
                s.pop();
            }

            if (s.empty()) {
                break;
            }
        }

        return maxGoodTime;
    }
};
