class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())
            return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        int f[n][m];
        for(int i = 0; i < n; ++ i)
            f[i][0] = matrix[i][0] == '1' ? 1 : 0;
        for(int i = 0; i < n; ++ i)
            for(int j = 1; j < m; ++ j)
                f[i][j] = matrix[i][j] == '1' ? f[i][j - 1] + 1 : 0;
        int ret = 0;
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ++ j) {
                int k = i, width = INT_MAX;
                while(k >= 0) {
                    if(f[k][j] == 0)
                        break;
                    width = min(width, f[k][j]);
                    ret = max(ret, width * (i - k + 1));
                    -- k;
                }
            }
        return ret;
    }
};