class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        if(S.size() == 1) {
            ans.push_back(S);
            vector<int> empty;
            ans.push_back(empty);
            return ans;
        }
        
        bool dupFlag = (S[S.size() - 2] == S[S.size() - 1]);
        vector<int> temp_S = S;
        temp_S.pop_back();
        ans = subsetsWithDup(temp_S);
        int num = ans.size(), dupLength = 0;
        for(int i = S.size() - 2; i >= 0; -- i)
            if(S[i] == S[S.size() - 1])
                ++ dupLength;
            else
                break;
        for(int i = 0; i < num; ++ i)
            if(!dupFlag || (ans[i].size() >= dupLength && ans[i][ans[i].size() - dupLength] == S[S.size() - 1])) {
                ans.push_back(ans[i]);
                ans[i].push_back(S[S.size() - 1]);
            }
        return ans;
    }
};