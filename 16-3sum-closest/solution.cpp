class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // 先排序保证数组的值是有序的
        int mindiff = INT_MAX;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int b = nums[left];
                int c = nums[right];
                int sum = a + b + c;
                int diff = fabs(sum - target);
                if (diff < mindiff) {
                    mindiff = diff;
                    res = sum;
                } else if (diff == 0) {
                    return sum;
                }

                if (sum <= target) {
                    left++; // 因为数组已排序，所以 left++ 会使 sum 变大，更接近 target
                } else {
                    right--; // 因为数组已排序，所以 left-- 会使 sum 变小，更接近 target
                }
            }
        }

        return res;
    }
};