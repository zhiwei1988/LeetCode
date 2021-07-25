class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = INT_MIN;

        int i = 0;
        int j = 0;
        for (; j < nums.size();) {
            if (j > 0 && nums[j] <= nums[j-1]) {
                i = j;
            }

            j++;
            maxLen = max(maxLen, j-i);
        }

        return maxLen;
    }
};