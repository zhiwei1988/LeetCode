class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipcount = 0;
        int len = nums.size();
        int res = 0;
        int i = 0;

        while (i < len) {
            if (i >= k && nums[i-k] == 2) {
                // 位置 i-k 是否翻转不影响位置 i
                flipcount--;
            }

            if (nums[i] == (flipcount % 2)) {
                flipcount++;
                if (i + k > len) {
                    return -1;
                }

                nums[i] = 2;
                res++;
            }

            i++;
        }

        return res;
    }
};
