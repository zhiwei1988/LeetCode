class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // 刚好包含 k 个不同整数的子数组个数 = 
        // 最多包含 k 个不同整数的子数组个数 - 最多包含 k-1 个不同整数的子数组个数 
        return atAlmost(nums, k) - atAlmost(nums, k-1);
    }

    // 返回包含最多 k 个不同整数的子数组个数
    int atAlmost(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> freq(len+1, 0);
        int left = 0;
        int right = 0;
        int count = 0;
        int res = 0;

        while (right < len) {
            if (freq[nums[right]] == 0) {
                count++;
            }

            freq[nums[right]]++;
            right++;

            while (count > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    count--;
                }

                left++;
            }

            res += right - left;
        }

        return res;
    }
};
