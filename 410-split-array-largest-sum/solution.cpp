class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // 从题意可知，最大值一定落在 [max(nums), sum(nums)] 区间内
        // 使用二分查找逐渐缩小范围

        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max = *max_element(nums.begin(), nums.end());
        int left = max;
        int right = sum;
        int res = max;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            //cout << "mid = " << mid << endl;
            int cnt = 0;
            int temp = 0;
            for (int i = 0; i < nums.size(); i++) {
                temp += nums[i];
                if (temp > mid) {
                    // 当前子数组的和已经超过了 mid，nums[i] 需要留给下个子数组
                    cnt++;
                    temp = nums[i];
                }
            }

            cnt++;

            if (cnt > m) {
                // 切的力度太细了，需要增大最大值
                left = mid + 1;
            } else {
                // 切的力度刚好或太粗，继续尝试缩小最大值
                if (cnt == m) {
                    res = mid;
                }
                right = mid - 1;
            }
        }


        return res;
    }
};
