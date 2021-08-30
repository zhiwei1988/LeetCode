class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<char>> chessBoard(n, vector<char>(n, '.')); // 构建棋盘 
        backtrace(chessBoard, 0);
        return m_res;
    }
    
private:
    bool Isvalid(vector<vector<char>> &chessBoard, int row, int col)
    {
        for (int i = 0; i < row; i++) {
            if (chessBoard[i][col] == 'Q') {
                // 如果同一列中已经摆放有皇后，则此位置不满足要求
                return false;
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < chessBoard.size(); j++) {
                // 如果斜对角线上已经摆放有皇后，则此位置不满足要求
                if (abs(row - i) == abs(col - j) && chessBoard[i][j] == 'Q') {
                    return false;
                } 
            }
        }
        
        return true;
    }
    
    void backtrace(vector<vector<char>> &chessBoard, int row)
    {
        if (row == chessBoard.size()) {
            m_res++;
            return;
        }
        
        for (int i = 0; i < chessBoard.size(); i++) {
            if (!Isvalid(chessBoard, row, i)) {
                continue;
            }
            
            chessBoard[row][i] = 'Q';
            backtrace(chessBoard, row + 1);
            chessBoard[row][i] = '.';
        }
    }
    
    int m_res = 0;
};
