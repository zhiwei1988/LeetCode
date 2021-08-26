class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum >= target) {
                    right--;
                } else {
                    // [left, right] 内的子数组组合都符合要求
                    res += (right - left);
                    left++;
                }
            }
        }

        return res;
    }
};
