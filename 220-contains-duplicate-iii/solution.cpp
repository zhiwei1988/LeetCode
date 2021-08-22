class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> seq;
        for (int i = 0; i < nums.size(); i++) {
            // 防止整形溢出，保证查找区间在 [x-t, x+t] 在 int 范围内
            auto it = seq.lower_bound(max(nums[i], INT_MIN + t) - t); 
            if (it != seq.end() && *it <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }

            seq.insert(nums[i]);
            if (i >= k) {
                seq.erase(nums[i-k]);
            }
        }

        return false;
    }
};