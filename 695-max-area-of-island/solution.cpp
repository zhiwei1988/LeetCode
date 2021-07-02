class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visted(rows, vector<bool>(cols, false));
        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !visted[i][j]) {
                    maxArea = max(maxArea, bfs(grid, visted, i, j));
                }
            }
        }

        return maxArea;
    }

private:
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visted, int x, int y)
    {
        int landNum = 0;
        queue<vector<int>> landQueue;
        landQueue.push(vector<int>{x, y});
        visted[x][y] = true;

        while (!landQueue.empty()) {
            auto size = landQueue.size();
            landNum += size;
            for (int i = 0; i < size; i++) {
                auto land = landQueue.front();
                landQueue.pop();
                for (auto dir : direction) {
                    int x = land[0] + dir[0];
                    int y = land[1] + dir[1];
                    if (InGrid(grid, x, y) && !visted[x][y] && grid[x][y] == 1) {
                        landQueue.push(vector<int>{x, y});
                        visted[x][y] = true;
                    }
                }
            }
        }

        return landNum;
    }

    bool InGrid(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || y < y || x >= grid.size() || y >= grid[0].size()) {
            return false;
        }

        return true;
    }

    vector<vector<int>> direction {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};