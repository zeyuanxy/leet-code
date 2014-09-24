class Solution {
private:
    int f[200][200];
    vector<string> temp;
    vector<vector<string> > ans;
public:
    void DFS(string &s, int depth) {
        if(s.length() == depth) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = depth; i < s.length(); ++ i) 
            if(f[depth][i] == 1) {
                temp.push_back(s.substr(depth, i - depth + 1));
                DFS(s, i + 1);
                temp.pop_back();
            }
    }

    vector<vector<string> > partition(string s) {
        ans.clear();
        int length = s.length();
        if(length == 0)
            return ans;

        memset(f, 0, sizeof(f));
        for(int i = 0; i < length; ++ i)
            f[i][i] = 1;
        for(int i = 2; i <= length; ++ i)
            for(int j = 0; j <= length - i; ++ j)
                if(s[j] == s[j + i - 1] && (i == 2 || f[j + 1][j + i - 2] == 1))
                    f[j][j + i - 1] = 1;

        DFS(s, 0);
        return ans;
    }
};