class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end()); // 排序
        int min = 0;
        int max = nums[len-1] - nums[0];
        // 第 k 个最小距离肯定在 [min, max] 间产生
        while (min < max) { // 二分
            int mid = (min + max) / 2;
            int ret = check(nums, k, mid); // 滑动窗口
            if (ret >= 0) { // 该间距大于等于第 k 个最小间距
                max = mid;
            } else { // 该间距小于第 k 个最小间距 
                min = mid + 1;
            }
        }

        return min;
    }

    int check(vector<int>& nums, int k, int val)
    {
        int left = 0;
        int right = 1;
        int count = 0;

        // 寻找间距小于等于 val 的整数对个数
        while (right < nums.size()) {
            int diff = nums[right] - nums[left];
            while (diff > val) {
                left++;
                diff = nums[right] - nums[left];
            }
            count += (right - left);
            right++;
        }

        if (count >= k) {
            return 1;
        } else {
            return -1;
        }
    }
};