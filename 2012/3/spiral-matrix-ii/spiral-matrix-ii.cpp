class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans;
        for(int i = 0; i < n; ++ i) {
            vector<int> temp;
            for(int j = 0; j < n; ++ j)
                temp.push_back(0);
            ans.push_back(temp);
        }
        
        int index = 0;
        for(int i = 0; i <= n / 2; ++ i) {
            for(int j = i; j < n - i; ++ j)
                ans[i][j] = ++index;
            for(int j = i + 1; j < n - i; ++ j)
                ans[j][n - i - 1] = ++index;
            for(int j = n - i - 2; j >= i; -- j)
                ans[n - i - 1][j] = ++index;
            for(int j = n - i - 2; j > i; -- j)
                ans[j][i] = ++index;
        }
        return ans;
    }
};