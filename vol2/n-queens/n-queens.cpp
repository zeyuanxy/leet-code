class Solution {
public:
    int pos[100] = {0};
    bool isUsed[100] = {0};
    int ans;
    
    bool check(int depth, int y) {
        for(int i = 0; i < depth; ++ i)
            if((depth - i) == abs(y - pos[i]))
                return false;
        return true;
    }
    
    void search(int depth, int maxDepth, vector<vector<string> > &ans, vector<string> &current) {
        if(depth == maxDepth) {
            ans.push_back(current);
            return;
        }
        
        for(int i = 0; i < maxDepth; ++ i)
            if(!isUsed[i] && check(depth, i)) {
                isUsed[i] = true;
                string temp(i, '.');
                temp.append("Q");
                temp.append(maxDepth - i - 1, '.');
                current.push_back(temp);
                pos[depth] = i;
                search(depth + 1, maxDepth, ans, current);
                current.pop_back();
                isUsed[i] = false;
            }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> temp;
        search(0, n, ans, temp);
        return ans;
    }
};