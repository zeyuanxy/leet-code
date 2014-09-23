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
    
    void search(int depth, int maxDepth) {
        if(depth == maxDepth) {
            ++ ans;
            return;
        }
        
        for(int i = 0; i < maxDepth; ++ i)
            if(!isUsed[i] && check(depth, i)) {
                isUsed[i] = true;
                pos[depth] = i;
                search(depth + 1, maxDepth);
                isUsed[i] = false;
            }
    }
    
    int totalNQueens(int n) {
        ans = 0;
        search(0, n);
        return ans;
    }
};