class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        if (m == 1 && n == 1) {
            return 0;
        }

        queue<tuple<int, int, int>> q;
        vector<vector<vector<bool>>> visted(m, vector<vector<bool>>(n, vector<bool>(k+1, false)));
        q.emplace(0, 0, k);
        visted[0][0][k] = true;

        int step = 0;
        while (!q.empty()) {
            step++;
            int size = q.size();
            while (size > 0) {
                auto unit = q.front();
                q.pop();
                size--;
                for (auto dir : directions) {
                    int x = get<0>(unit) + dir[0];
                    int y = get<1>(unit) + dir[1];
                    int rest = get<2>(unit);

                    if (!InGrid(x, y)) {
                        continue;
                    }

                    if (grid[x][y] == 0 && !visted[x][y][rest]) {
                        if (x == m-1 && y == n-1) {
                            return step;
                        }
                        q.emplace(x, y, rest);
                        visted[x][y][rest] = true;
                    } else if (grid[x][y] == 1 && rest > 0 && !visted[x][y][rest-1]) {
                        q.emplace(x, y, rest-1);
                        visted[x][y][rest-1] = true;
                    }
                }
            }
        }

        return -1;
    }

private:
    bool InGrid(int x, int y)
    {
        if (x < 0 || y < 0 || x >= m || y >= n) {
            return false;
        }

        return true;
    }
    
    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int m = 0;
    int n = 0;
};
