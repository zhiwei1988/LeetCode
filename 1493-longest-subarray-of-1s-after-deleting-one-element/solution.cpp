class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = 0;
        int count = 0; // 值不是1的元素个数
        int res = 0;

        while (right < len) {
            if (nums[right] != 1) {
                count++;
            }

            right++;

            while (count > 1) {
                if (nums[left] != 1) {
                    count--;
                }

                left++;
            }

            res = max(res, right-left);
        }

        return res-1;
    }
};
