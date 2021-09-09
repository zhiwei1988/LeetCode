class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        // 前后各插入一个 0，确保每个柱子都可以遍历到
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int left = s.top() + 1; // s.top() 是 height 之前第1个比 height 低的位置
                int right = i - 1; // i 是 height 之后第1个比 height 低的位置
                int area = height * (right - left + 1); // 以 height 为高的矩形面积
                result = max(result, area);
            }
            s.push(i);
        }

        return result;
    }
};
