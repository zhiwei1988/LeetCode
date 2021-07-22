class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> seaQ;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    seaQ.emplace(i, j);
                }
            }
        }
        
        if (seaQ.size() == grid.size() * grid[0].size()) {
            return -1;
        }
        
        int len = -1;
        while (!seaQ.empty()) {
            auto size = seaQ.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = seaQ.front();
                seaQ.pop();
                for (auto dir : directions) {
                    int x1 = x + dir[0];
                    int y1 = y + dir[1];
                    if (!InGrid(x1, y1, grid)) {
                        continue;
                    }

                    if (grid[x1][y1] == 0) {
                        seaQ.emplace(x1, y1);
                        grid[x1][y1] = 2;
                    }
                }
            }

            len++;
        }

        return len;
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