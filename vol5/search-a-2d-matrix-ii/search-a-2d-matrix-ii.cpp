class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        if (target < matrix[0][0]) {
            return false;
        }
        int n = matrix.size(), m = matrix[0].size();
        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                --i;
            } else if (matrix[i][j] < target) {
                ++j;
            }
        }
        return false;
    }
};