class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n-1; i++) {
            // 不断寻找能跳跃到的最远距离
            farthest = max(farthest, i + nums[i]);
            // 可能遇到 0 了
            if (farthest <= i) return false;
        }

        return farthest >= (n - 1);
    }
};
