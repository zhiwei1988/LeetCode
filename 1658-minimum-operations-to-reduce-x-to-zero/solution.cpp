class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }

        if (x > sum) {
            return -1;
        }

        int dst = sum - x;
        int left = 0;
        int right = 0;
        int maxOperate = INT_MIN;
        int count = 0;

        while (right < size) {
            count += nums[right];
            right++;

            while (count > dst) {
                count -= nums[left];
                left++;
            }

            if (count == dst) {
                maxOperate = max(maxOperate, right-left);
            }
        }

        return maxOperate == INT_MIN ? -1 : size - maxOperate;
    }
};
