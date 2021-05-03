class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int farthest = 0; /* 从 [i, end] 区间内的每个元素起跳，最远能跳到的位置 */
        int jump = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(nums[i]+i, farthest);
            if (i == end) {
                end = farthest;
                jump++;
            }
        }

        return jump;
    }
};
