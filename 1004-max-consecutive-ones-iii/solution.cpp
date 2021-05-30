class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int frequency = 0;
        int left = 0;
        int right = 0;
        int size = nums.size();

        while (right < size) {
            if (nums[right] == 1) {
               frequency++; 
            }

            right++;

            // 当窗口的大小大于，窗口中 1 的个数加上k个0时
            // 说明窗口中的所有数字不可能形成连续的 1 了
            // 窗口需要减小
            if (right - left > frequency + k) {
                if (nums[left] == 1) {
                    frequency--;
                }

                left++;
            }
        }
        
        return right - left;
    }
};
