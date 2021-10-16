class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> helpNums(nums);
        vector<int> res;
        sort(helpNums.begin(), helpNums.end());
        for (int i = 0; i < nums.size(); i++) {
            auto pos = lower_bound(helpNums.begin(), helpNums.end(), nums[i]);
            res.push_back(pos - helpNums.begin());
        }
        return res;
    }
};
