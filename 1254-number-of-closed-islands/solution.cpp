class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (!ArriveBorder(grid, visited, i, j)) {
                        res++;
                    }
                }
            }
        }

        return res;
    }

private:
    bool ArriveBorder(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
    {
        queue<vector<int>> landQueue;
        landQueue.push(vector<int>{x, y});
        visited[x][y] = true;

        bool res = false;
        while (!landQueue.empty()) {
            auto size = landQueue.size();
            for (int i = 0; i < size; i++) {
                auto land = landQueue.front();
                landQueue.pop();
                for (auto dir : directions) {
                    int x1 = land[0] + dir[0];
                    int y1 = land[1] + dir[1];
                    if (!InGrid(grid, x1, y1)) {
                        res = true;
                        continue;
                    }

                    if (visited[x1][y1]) {
                        continue;
                    }

                    if (grid[x1][y1] == 0) {
                        landQueue.push(vector<int>{x1, y1});
                        visited[x1][y1] = true;
                    }
                }
            }
        }

        return res;
    }

    bool InGrid(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return false;
        }

        return true;
    }

    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};    
};