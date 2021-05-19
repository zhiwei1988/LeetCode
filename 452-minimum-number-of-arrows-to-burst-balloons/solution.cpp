class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }

        std::sort(begin(points), end(points), [](const auto &left, const auto &right) {
            // 先按起点从大到小排列，如果起点相同则按重点从小到大排列
            if (left[0] == right[0]) {
                return left[1] < right[1];
            }

            return left[0] > right[0];
        });

        // 一组气球是否能用同一支箭射穿，关键看其他气球是否能覆盖个头最小的那个气球
        int count = 1;
        int left = points[0][0]; 
        for (int i = 1; i < points.size(); i++) {
            if (points[i][1] < left) {
                // 更新个头最小的气球
                left = points[i][0];
                count++;
            }
        }

        return count;
    }
};
