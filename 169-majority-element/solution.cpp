class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return divide(nums, 0, nums.size()-1);
    }

private:
    // 返回子数组中出现最多的元素
    int divide(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        int leftRes = divide(nums, left, mid);
        int rightRes = divide(nums, mid+1, right);

        if (leftRes == rightRes) {
            return leftRes;
        }

        int leftNum = count(nums, left, right, leftRes);
        int rightNum = count(nums, left, right, rightRes);
        return leftNum > rightNum ? leftRes : rightRes;
    }

    // 返回子数组中目标元素的个数
    int count(vector<int>& nums, int left, int right, int target) {
        int res = 0;
        while (left <= right) {
            if (nums[left] == target) {
                res++;
            }

            left++;
        }

        return res;
    }
};
