class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        int unrevealedCnt = 0;
        vector<vector<bool>> visted(m, vector<bool>(n, false));
        vector<vector<int>> bMap(m, vector<int>(n, 0));

        UpdateBoard(board, bMap);

        queue<vector<int>> squareQueue;
        squareQueue.push(click);
        visted[click[0]][click[1]] = true;

        while (!squareQueue.empty()) {
            size_t qSize = squareQueue.size();
            for (int i = 0; i < qSize; i++) {
                auto square = squareQueue.front();
                squareQueue.pop();
                int x = square[0];
                int y = square[1];
                if (board[x][y] == 'M') {
                    board[x][y] = 'X';
                    return board;
                } else if (board[x][y] == 'E') {
                    if (bMap[x][y] != 0) {
                        board[x][y] = bMap[x][y] + '0';
                        visted[x][y] = true;
                        continue;
                    } else {
                        board[x][y] = 'B';
                        GoNext(board, squareQueue, visted, x-1, y);
                        GoNext(board, squareQueue, visted, x+1, y);
                        GoNext(board, squareQueue, visted, x, y-1);
                        GoNext(board, squareQueue, visted, x, y+1);
                        GoNext(board, squareQueue, visted, x-1, y-1);
                        GoNext(board, squareQueue, visted, x+1, y+1);
                        GoNext(board, squareQueue, visted, x-1, y+1);
                        GoNext(board, squareQueue, visted, x+1, y-1);
                    }
                }
            }
        }

        return board;
    }

private:
    void GoNext(vector<vector<char>>& board, queue<vector<int>> &squareQueue,
        vector<vector<bool>> visted, int x, int y) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return;
        }

        if (visted[x][y]) {
            return;
        }

        if (board[x][y] != 'E' && board[x][y] != 'M') {
            return;
        }

        visted[x][y] = true;
        squareQueue.push(vector<int> {x, y});
    }

    void UpdateBoard(vector<vector<char>>& board, vector<vector<int>> &bMap)
    {
        for (int i = 0 ; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'M') {
                    UpdateSquare(bMap, i+1, j);
                    UpdateSquare(bMap, i-1, j);
                    UpdateSquare(bMap, i, j+1);
                    UpdateSquare(bMap, i, j-1);
                    UpdateSquare(bMap, i+1, j+1);
                    UpdateSquare(bMap, i+1, j-1);
                    UpdateSquare(bMap, i-1, j+1);
                    UpdateSquare(bMap, i-1, j-1);
                }
            }
        }
    }

    void UpdateSquare(vector<vector<int>> &bMap, int x, int y)
    {
        if (x < 0 || y < 0 || x >= bMap.size() || y >= bMap[0].size()) {
            return;
        }

        bMap[x][y]++;
    }
};
