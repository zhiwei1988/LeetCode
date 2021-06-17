class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visted(m, vector<bool>(n, false));
        int islandNums = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visted[i][j] == false) {
                    backtrace(grid, visted, i, j, m, n);
                    islandNums++;
                }
            }
        }

        return islandNums;
    }

private:
    void backtrace(vector<vector<char>> &grid, vector<vector<bool>> &visted,
                   int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        if (visted[i][j] == true) {
            return;
        }
        
        if (grid[i][j] == '0') {
            return;
        }

        visted[i][j] = true;

        backtrace(grid, visted, i+1, j, m, n);
        backtrace(grid, visted, i-1, j, m, n);
        backtrace(grid, visted, i, j+1, m, n);
        backtrace(grid, visted, i, j-1, m, n);
    }
};
