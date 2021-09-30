struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // 寻找根节点
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        parent[x] = find(parent[x]); // 路径压缩
        return parent[x];
    }

    void Union(int x, int y) {
        int parentx = find(x);
        int parenty = find(y);
        if (parentx == parenty) {
            return;
        }
        parent[parenty] = parentx;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DSU dsu(m*n);
        vector<vector<int>> board(m, vector<int>(n, 0));
        vector<int> result;
        int islandNum = 0;
        for (const auto &pos : positions) {
            int x = pos[0];
            int y = pos[1];
            if (board[x][y] == 1) {
                result.push_back(islandNum);
                continue;
            }

            board[x][y] = 1;
            islandNum++;
            for (const auto &dir : directions) {
                int x1 = x + dir[0];
                int y1 = y + dir[1];
                if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n || board[x1][y1] != 1) {
                    continue;
                }

                int parent1 = dsu.find(x * n + y);
                int parent2 = dsu.find(x1 * n + y1);
                if (parent1 != parent2) {
                    dsu.Union((x * n + y), (x1 * n + y1));
                    islandNum--; // 与其他岛屿合并了, 合并的动作可能存在多次
                }
            }

            result.push_back(islandNum);
        }

        return result;
    }

    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
