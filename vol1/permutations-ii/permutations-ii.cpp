class Solution {
private:
    bool used[100];
    vector<int> temp;
    vector<vector<int> > ans;
public:
    void DFS(int depth, int n, vector<int> &num) {
        if(depth == n) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i < n; ++ i)
            if(!used[i]) {
                if(i != 0 && num[i] == num[i - 1] && !used[i - 1])
                    continue;
                used[i] = true;
                temp.push_back(num[i]);
                DFS(depth + 1, n, num);
                temp.pop_back();
                used[i] = false;
            }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        ans.clear();
        if(num.empty()) 
            return ans;
            
        sort(num.begin(), num.end());
        //used = new bool[num.size()];
        memset(used, false, sizeof(used));
        DFS(0, num.size(), num);
        return ans;
    }
};