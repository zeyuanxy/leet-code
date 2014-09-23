class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if(matrix.empty())
            return ans;
        int row = matrix.size(), col = matrix[0].size();
        int start = 0;
        while(row > 1 && col > 1) {
            for(int i = 0; i < col - 1; ++ i)
                ans.push_back(matrix[start][start + i]);
            for(int i = 0; i < row - 1; ++ i)
                ans.push_back(matrix[start + i][start + col - 1]);
            for(int i = 0; i < col - 1; ++ i)
                ans.push_back(matrix[start + row - 1][start + col - 1 - i]);
            for(int i = 0; i < row - 1; ++ i)
                ans.push_back(matrix[start + row - 1 - i][start]);
            ++ start;
            row -= 2;
            col -= 2;
        };
        if(row == 1)
            for(int i = 0; i < col; ++ i)
                ans.push_back(matrix[start][start + i]);
        else if(col == 1)
            for(int i = 0; i < row; ++ i)
                ans.push_back(matrix[start + i][start]);
        return ans;
    }
};