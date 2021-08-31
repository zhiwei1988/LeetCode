class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> landMap;
        int index = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area = 0;
                    GetArea(i, j, grid, index);
                    landMap[index] = area;
                    res = max(res, area);
                    index++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                     // 用于去重，可能存在多个方向属于通一个岛屿
                    unordered_set<int> landSet;
                    area = 1;
                    for (auto dir : directions) {
                        if (!InGrid(i+dir.first, j+dir.second)) {
                            continue;
                        }
                        
                        int land = grid[i+dir.first][j+dir.second];
                        if (landSet.count(land) == 0) {
                            landSet.insert(land);
                            area += landMap[land]; // 计算各个方向岛屿面积
                        }
                    }                  
                    
                    res = max(res, area);
                }
            }
        }

        return res;
    }

private:
    // 对岛屿进行编号，并返回岛屿面积
    void GetArea(int i, int j, vector<vector<int>>& grid, int index)
    {
        if (!InGrid(i, j)) {
            return;
        }
        
        if (grid[i][j] != 1) {
            return;
        }

        grid[i][j] = index;
        area++;

        for (auto dir : directions) {
            GetArea(i + dir.first, j + dir.second, grid, index);
        }
    }

    bool InGrid(int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return false;
        }

        return true;
    }

    vector<pair<int, int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
    int res = 0; 
    int area = 0; 
    int n = 0;
};
