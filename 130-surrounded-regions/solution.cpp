class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (m <= 2 || n <= 2) {
            return;
        }
        
        vector<vector<bool>> noNeedChange(m, vector<bool>(n, false));
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (board[i][j] == 'O' && !noNeedChange[i][j]) {
                    queue<vector<int>> vistedQ;
                    if (NeedChange(board, vistedQ, i, j)) {
                        while (!vistedQ.empty()) {
                            auto member = vistedQ.front();
                            vistedQ.pop();
                            board[member[0]][member[1]] = 'X';
                        } 
                    } else {
                        while (!vistedQ.empty()) {
                            auto member = vistedQ.front();
                            vistedQ.pop();
                            noNeedChange[member[0]][member[1]] = true;
                        } 
                    }
                }
            }
        }
    }
private:
    bool NeedChange(vector<vector<char>> &board, queue<vector<int>> &vistedQ, 
                    int i, int j) {
        int m = board.size();
        int n = board[0].size();
        queue<vector<int>> q;
        q.push(vector<int>{i, j});
        vector<vector<bool>> visted(m, vector<bool>(n, false));
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto member = q.front();
                q.pop();
                int x = member[0];
                int y = member[1];
                
                if (visted[x][y]) {
                    continue;
                }

                visted[x][y] = true;
                vistedQ.push(vector<int>{x, y});
                
                if (x == 0 || x == m-1 || y == 0 || y == n-1) {
                    if (board[x][y] == 'O') {
                        return false;
                    } else {
                        continue;
                    }
                } else {
                    if (board[x-1][y] == 'O') {
                        q.push(vector<int>{x-1, y});
                    }

                    if (board[x+1][y] == 'O') {
                        q.push(vector<int>{x+1, y});
                    }

                    if (board[x][y-1] == 'O') {
                        q.push(vector<int>{x, y-1});
                    }

                    if (board[x][y+1] == 'O') {
                        q.push(vector<int>{x, y+1});
                    }
                }
            }
        }

        return true;
    }
};
