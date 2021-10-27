class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        // 对于全排列问题，如果元素有重复值，必须先排序，用于后续的去重判断
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> level;
        dfs(nums, res, level, used);
        return res;
    }
    
private:
    void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int> &level, vector<bool> &used) {
        if (level.size() == nums.size()) {
            res.push_back(level);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (used[i] || (i != 0 && nums[i-1] == nums[i] && !used[i-1])) {
                    // 当出现前后两个元素值相同时，仅当前一个元素已经被使用过了，当前元素
                    // 才能被使用，否则就会出现重复的排列
                    continue;
                } else {
                    used[i] = true;
                    level.push_back(nums[i]);
                    dfs(nums, res, level, used);
                    level.pop_back();
                    used[i] = false;
                }
            }
        }
    }
};
