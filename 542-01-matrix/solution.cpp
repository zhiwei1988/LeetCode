class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> memberQueue;
        int distance = 1;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    mat[i][j] = -1;
                    memberQueue.push(vector<int> {i, j});
                } else {
                    mat[i][j] = 0; 
                }
            }
        }

        while (!memberQueue.empty()) {
            auto size = memberQueue.size();
            for (int i = 0; i < size; i++) {
                auto m = memberQueue.front();
                memberQueue.pop();

                if (InMatrix(mat, m[0]+1, m[1]) && mat[m[0]+1][m[1]] == 0) {
                    mat[m[0]+1][m[1]] = distance;
                    memberQueue.push(vector<int> {m[0]+1, m[1]});
                }

                if (InMatrix(mat, m[0]-1, m[1]) && mat[m[0]-1][m[1]] == 0) {
                    mat[m[0]-1][m[1]] = distance;
                    memberQueue.push(vector<int> {m[0]-1, m[1]});
                }

                if (InMatrix(mat, m[0], m[1]+1) && mat[m[0]][m[1]+1] == 0) {
                    mat[m[0]][m[1]+1] = distance;
                    memberQueue.push(vector<int> {m[0], m[1]+1});
                }

                if (InMatrix(mat, m[0], m[1]-1) && mat[m[0]][m[1]-1] == 0) {
                    mat[m[0]][m[1]-1] = distance;
                    memberQueue.push(vector<int> {m[0], m[1]-1});
                }
            }

            distance++;
        }

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == -1) {
                    mat[i][j] = 0;
                }
            }
        }

        return mat;
    }

private:
    bool InMatrix(vector<vector<int>> &mat, int x, int y)
    {
        if (x < 0 || y < 0 || x >= mat.size() || y >= mat[0].size()) {
            return false;
        }

        return true;
    }
};