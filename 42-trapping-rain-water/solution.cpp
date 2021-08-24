class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int lmax = 0;
        int rmax = 0;
        int res = 0;

        // 某个位置能够容纳的水量 = min(lmax, rmax) - heigh[i]
        while (left <= right) {
            lmax = max(lmax, height[left]);
            rmax = max(rmax, height[right]);

            if (lmax < rmax) {
                res += lmax - height[left];
                left++;
            } else {
                res += rmax - height[right];
                right--;
            }
        }

        return res;
    }
};
