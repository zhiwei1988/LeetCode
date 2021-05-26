class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        /* 先对信封按宽度进行升序排序，如果宽度相同，按高度降序 */
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            // 如果高度不按降序排序的话，会出现宽度相同的信封被认为可以嵌套
            // 比如：[[4,5],[4,6],[6,7],[2,3],[1,1]]
            if (a[0] < b[0]) {
                return true;
            } else if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return false;
            }
        });

        /* 取信封高度作为一个新的数组 */
        vector<int> numbers;
        for (auto &m : envelopes) {
            numbers.push_back(m[1]);
        }

        /* 求最长递增子序列，即可得到可嵌套的信封数 */
        return lengthOfLIS(numbers);
    }

private:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            if (!dp.size() || nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            } else {
                // 在 dp 中找出第一个大于 nums[i] 的元素，将它的值改成 nums[i]
                *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
            }
        }

        return dp.size();
    }
};
