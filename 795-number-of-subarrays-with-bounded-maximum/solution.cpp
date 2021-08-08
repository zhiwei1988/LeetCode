class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return LessEqualsThan(nums, right) - LessEqualsThan(nums, left-1);
    }

private:
    int LessEqualsThan(vector<int>& nums, int k)
    {
        int len = nums.size();
        int res = 0;
        // 循环不变量：nums[left..right] 里的所有元素都小于等于 k
        for (int left = 0, right = 0; right < len; right++) {
            if (nums[right] > k) {
                left = right + 1;
            } else {
                res += right - left + 1; // 前缀和
            }
        }
        return res;
    }
};