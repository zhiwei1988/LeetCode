class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int preProduct = 1;
        int preSubarray = 0;
        int res = 0;
        int left = 0;
        int right = 0;
        if (k <= 1) {
            return 0;
        }
        while (right < nums.size()) {
            preProduct *= nums[right];

            while (preProduct >= k & left <= right) {
                preProduct /= nums[left];
                left++;
                preSubarray--;
            }

            preSubarray++;
            res += preSubarray;
            right++;
        }

        return res;
    }
};