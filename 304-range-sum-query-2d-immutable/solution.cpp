class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // sum[i+1][j+1] 表示以 matrix[0][0] 为左上角，以 matrix[i][j] 为右下角
        // 的矩形内的所有元素之和，sum[0][j] == 0, sum[i][0] == 0
        sum.resize(m+1, vector<int>(n+1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] + matrix[i][j] - sum[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
};
