class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int unicom = image[sr][sc];
        int rows = image.size();
        int cols = image[0].size();
        vector<vector<bool>> visted(rows, vector<bool>(cols, false));
        dfs(image, visted, sr, sc, unicom, newColor);

        return image;
    }

private:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visted, 
        int x, int y, int unicom, int color)
    {
        if (!InGrid(grid, x, y)) {
            return;
        }

        if (visted[x][y]) {
            return;
        }

        if (grid[x][y] != unicom) {
            return;
        }

        grid[x][y] = color;
        visted[x][y] = true;

        for (auto dir : direction) {
            int x1 = x + dir[0];
            int y1 = y + dir[1];
            dfs(grid, visted, x1, y1, unicom, color);
        }
    }

    bool InGrid(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return false;
        }

        return true;
    }

    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};