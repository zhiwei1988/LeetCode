class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int score = 0;
        int maxScore = 0;
        unordered_set<int> numSet;

        while (right < nums.size()) {
            while (numSet.count(nums[right])) {
                numSet.erase(nums[left]);
                score -= nums[left];
                left++;
            }

            score += nums[right];
            maxScore = max(maxScore, score);
            numSet.insert(nums[right]);
            right++;
        }

        return maxScore;
    }
};