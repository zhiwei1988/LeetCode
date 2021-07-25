class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }

        int j = 0; // [0, j] 的元素为符合要求的元素，循环不变量
        bool needDelete = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i]) {
                if (!needDelete) {
                    j++;
                    nums[j] = nums[i];
                    needDelete = true;   
                }
            } else {
                j++;
                nums[j] = nums[i];
                needDelete = false;
            }
        }

        return j + 1;
    }
};