class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& vec, int k, int n) {
        if (k == 0 || n == 0) {
            if (k == 0 && n == 0) {
                ans.push_back(vec);
            }
            return;
        }
        int start = vec.empty()?1:vec.back() + 1;
        for (int i = start; i <= 9; ++i) {
            if (n < i) {
                break;
            }
            vec.push_back(i);
            dfs(ans, vec, k - 1, n - i);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;
        dfs(ans, vec, k, n);
        return ans;
    }
};