class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> ans;
        for(int i = 0; i <= triangle[triangle.size() - 1].size() - 1; ++ i)
            ans.push_back(triangle[triangle.size() - 1][i]);
        for(int i = triangle.size() - 2; i >= 0; -- i)
        {
            for(int j = 0; j < triangle[i].size(); ++ j)
                ans[j] = triangle[i][j] + min(ans[j], ans[j + 1]);
        }
        return ans[0];
    }
};