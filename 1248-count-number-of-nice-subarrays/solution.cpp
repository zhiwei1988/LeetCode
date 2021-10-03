class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }

    /**
     * 最多存在 n 奇数数字的子数组个数
     * @param n
     * @return
     */
    int atMost(vector<int>& nums, int n)
    {
        int left = 0;
        int oddNum = 0;
        int size = nums.size();
        int res = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] % 2 == 1) {
                oddNum++;
            }

            while (oddNum > n) {
                oddNum -= nums[left++] % 2;
            }

            res += (i - left + 1);
        }

        return res;
    }
};
