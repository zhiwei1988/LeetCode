class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int maxLen = INT_MIN;
        deque<int> maxQ; // 队列顶端存储着窗口中元素的最大值
        deque<int> minQ; // 队列顶端存储着窗口中元素的最小值
        int left = 0;
        int right = 0;
        int size = nums.size();

        while (right < size) {
            while (!maxQ.empty() && maxQ.back() < nums[right]) {
                maxQ.pop_back();
            }

            while (!minQ.empty() && minQ.back() > nums[right]) {
                minQ.pop_back();
            }

            maxQ.push_back(nums[right]);
            minQ.push_back(nums[right]);
            
            right++;
            
            // 如果窗口中元素的最大值-最小值没有超过 limit，
            // 则其他元素间的绝对差，肯定也不会超过 limit
            while (!maxQ.empty() && !minQ.empty() && fabs(maxQ.front() - minQ.front()) > limit) {
                if (!minQ.empty() && minQ.front() == nums[left]) {
                    minQ.pop_front();
                }

                if (!maxQ.empty() && maxQ.front() == nums[left]) {
                    maxQ.pop_front();
                }

                left++;
            }
            
            maxLen = max(maxLen, right-left);
        }

        return maxLen;
    }
};
