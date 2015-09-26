class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int **ans = new int*[m];
        for(int i = 0; i < m; ++ i)
            ans[i] = new int[n];
        for(int i = 0; i < m; ++ i)
            for(int j = 0; j < n; ++ j) 
            {
                ans[i][j] = 0;
                if(obstacleGrid[i][j] == 1)
                    continue;
                if(i == 0 && j == 0)
                    ans[i][j] = 1;
                if(i > 0)
                    ans[i][j] += ans[i - 1][j];
                if(j > 0)
                    ans[i][j] += ans[i][j - 1];
            }
        return ans[m - 1][n - 1];
    }
};