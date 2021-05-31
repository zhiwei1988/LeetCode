class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int cnt = 0;
        uint minCnt = 0xFFFFFFFF;

        while (right < nums.size()) {
            int num = nums[right];
            right++;
            sum += num;

            while (sum >= s) {
                int num = nums[left];
                cnt  = right - left;
                if (cnt < minCnt) minCnt = cnt;

                left++;
                sum -= num;
            }
        }

        if (left == 0) minCnt = 0;

        return minCnt;
    }
};
