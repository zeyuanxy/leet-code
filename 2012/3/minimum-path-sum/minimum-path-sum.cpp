class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        int **ans = new int*[m];
        for(int i = 0; i < m; ++ i)
        {
            ans[i] = new int[n];
            for(int j = 0; j < n; ++ j)
                ans[i][j] = 0x0fffffff;
        }
        ans[0][0] = grid[0][0];
        for(int i = 0; i < m; ++ i)
            for(int j = 0; j < n; ++ j)
                if(i != 0 || j != 0)
                {
                    if(i > 0)
                        ans[i][j] = min(ans[i][j], ans[i - 1][j] + grid[i][j]);
                    if(j > 0)
                        ans[i][j] = min(ans[i][j], ans[i][j - 1] + grid[i][j]);
                }
        return ans[m - 1][n - 1];
    }
};