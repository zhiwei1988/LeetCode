class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxAreas = INT_MIN;
        while (left < right) {
            if (height[left] < height[right]) {
                auto area = height[left] * (right - left);
                maxAreas = max(maxAreas, area);
                left++;
            } else {
                auto area = height[right] * (right - left);
                maxAreas = max(maxAreas, area);
                right--;
            }
        }

        return maxAreas;
    }
};