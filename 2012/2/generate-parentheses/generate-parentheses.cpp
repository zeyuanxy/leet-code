class Solution {
public:
    void DFS(vector<string> &ans, string str, int left, int right, int n) {
        if(left == n && right == n){
            ans.push_back(str);
            return;
        }
        if(left < n)
            DFS(ans, str + "(", left + 1, right, n);
        if(right < left)
            DFS(ans, str + ")", left, right + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        DFS(ans, "", 0, 0, n);
        return ans;
    }
};