class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        auto rSize = heights.size();
        if (rSize == 0) {
            return res;
        }

        auto cSize = heights[0].size();
        // 太平洋的水能到达的位置
        vector<vector<bool>> pacificWaterArrive(rSize, vector<bool>(cSize, false)); 
        // 大西洋的水能到达的位置
        vector<vector<bool>> atlanticWaterArrive(rSize, vector<bool>(cSize, false)); 

        for (int r = 0; r < rSize; r++) {
            WaterArrive(heights, r, 0, INT_MIN, pacificWaterArrive);
            WaterArrive(heights, r, cSize-1, INT_MIN, atlanticWaterArrive);
        }

        for (int c = 0; c < cSize; c++) {
            WaterArrive(heights, 0, c, INT_MIN, pacificWaterArrive);
            WaterArrive(heights, rSize-1, c, INT_MIN, atlanticWaterArrive);
        }

        for (int i = 0; i < rSize; i++) {
            for (int j = 0; j < cSize; j++) {
                if (pacificWaterArrive[i][j] && atlanticWaterArrive[i][j]) {
                    res.push_back(vector<int> {i, j});
                }
            }
        }

        return res;
    }

private:
    void WaterArrive(vector<vector<int>>& heights, int r, int c, 
        int preHeight, vector<vector<bool>> &waterArrive)
    {
        if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size()) {
            return;
        }

        if (waterArrive[r][c] || heights[r][c] < preHeight) {
            return;
        }

        waterArrive[r][c] = true;
        WaterArrive(heights, r+1, c, heights[r][c], waterArrive);
        WaterArrive(heights, r-1, c, heights[r][c], waterArrive);
        WaterArrive(heights, r, c+1, heights[r][c], waterArrive);
        WaterArrive(heights, r, c-1, heights[r][c], waterArrive);
    }
};
