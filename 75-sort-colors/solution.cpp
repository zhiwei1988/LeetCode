class Solution {
public:
    // all in [0, p1) == 0
    // all in [p1, i) == 1
    // all in (p2, len-1] == 2
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return;
        }

        int p1 = 0;
        int p2 = size - 1;
        for (int i = 0; i < size;) {
            if (i > p2) {
                return;
            }

            if (nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2--;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p1]);
                p1++;
                i++;
            } else {
                i++;
            }
        }
    }
};