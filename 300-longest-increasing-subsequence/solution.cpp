class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            if (!dp.size() || nums[i] > dp.back()) {
                // 新生成一个堆
                // dp 元素是按从小到大排列的，如果新元素比 dp 尾部的元素还大，那就因该新起一个堆
                dp.push_back(nums[i]);
            } else {
                // 在所有可放置新元素的堆中（堆顶元素比新元素大）找出最左边的堆，将新元素放置上去
                *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
            }
        }

        return dp.size();
    }
};
