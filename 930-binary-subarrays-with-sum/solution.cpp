class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum_lo = 0; // 从 lo 到当前位置的和
        int sum_hi = 0; // 从 hi 到当前位置的和
        int hi = 0;
        int lo = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum_lo += nums[i];

            while (lo < i && sum_lo > goal) {
                sum_lo -= nums[lo++];
            }

            sum_hi += nums[i];

            while (hi < i && (sum_hi > goal || (sum_hi == goal && nums[hi] == 0))) {
                sum_hi -= nums[hi++];
            }

            if (sum_hi == goal) {
                res += (hi - lo + 1);
            }
        }

        return res;
    }
};
