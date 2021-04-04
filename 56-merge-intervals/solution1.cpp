class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /* 先将区间按起始元素按升序进行排序，如果起始元素相同，则按结束元素按升序排序 */
        std::sort(begin(intervals), end(intervals), [] (const auto &left, const auto &right) -> bool {
            if (left[0] == right[0]) {
                return left[1] < right[1]; 
            }

            return left[0] < right[0];
        });

        int left = intervals[0][0];
        int right = intervals[0][1];

        vector<vector<int>> res;

        for (int i = 1; i < intervals.size(); i++) {
            if (right < intervals[i][0]) {
                res.push_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            } else if (right < intervals[i][1]) {
                right = intervals[i][1];
            }
        }

        res.push_back(vector<int>{left, right});

        return res;
    }
};
