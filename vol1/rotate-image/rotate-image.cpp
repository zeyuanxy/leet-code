class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for(int i = 0; i < matrix.size() / 2; ++ i) {
            for(int j = 0; j < matrix.size() - 1 - i * 2; ++ j) {
                int temp = matrix[i][i + j];
                matrix[i][i + j] = matrix[matrix.size() - 1 - i - j][i];
                matrix[matrix.size() - 1 - i - j][i] = matrix[matrix.size() - 1 - i][matrix.size() -1 - i - j];
                matrix[matrix.size() - 1 - i][matrix.size() -1 - i - j] = matrix[i + j][matrix.size() - 1 - i];
                matrix[i + j][matrix.size() - 1 - i] = temp;
            }
        }
    }
};