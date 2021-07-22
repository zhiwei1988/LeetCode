class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rottenOrigins;
        int freshOriginCnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                auto &cell = grid[i][j];
                if (cell == 2) {
                    rottenOrigins.emplace(i, j);
                    cell = 3;
                } else if (cell == 1) {
                    freshOriginCnt++;
                }
            }
        }

        int minute = 0;
        while (!rottenOrigins.empty()) {
            if (freshOriginCnt == 0) {
                return minute;
            }
            auto size = rottenOrigins.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = rottenOrigins.front();
                rottenOrigins.pop();
                for (auto dir : directions) {
                    int x1 = x + dir[0];
                    int y1 = y + dir[1];
                    if (!InGrid(x1, y1, grid)) {
                        continue;
                    }

                    if (grid[x1][y1] == 1) {
                        rottenOrigins.emplace(x1, y1);
                        grid[x1][y1] = 3;
                        freshOriginCnt--;
                    }
                }
            }

            minute++;
        }

        if (freshOriginCnt == 0) {
            return minute;
        }

        return -1;
    }

private:
    bool InGrid(int x, int y, vector<vector<int>> &grid) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return false;
        }

        return true;
    }

    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};