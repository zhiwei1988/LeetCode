class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visted(n*n + 1, false);
        queue<pair<int, int>> q; // first 玩家位置，second 移动次数
        q.emplace(1, 0);

        while (!q.empty()) {
            auto size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                for (int j = 1; j <= 6; j++) {
                    int nxt = p.first + j;
                    if (nxt > n * n) {
                        continue;
                    }

                    auto rc = id2rc(nxt, n);
                    if (board[rc.first][rc.second] > 0) {
                        nxt = board[rc.first][rc.second];
                    }

                    if (nxt == n * n) {
                        return p.second + 1;
                    }

                    if (!visted[nxt]) {
                        visted[nxt] = true;
                        q.emplace(nxt, p.second + 1);
                    }
                }
            }
        }

        return -1;
    }
private:
    pair<int, int> id2rc(int id, int n) {
        int r = (id - 1) / n, c = (id - 1) % n;
        if (r % 2 == 1) {
            c = n - 1 - c;
        }
        return {n - 1 - r, c};
    }
};