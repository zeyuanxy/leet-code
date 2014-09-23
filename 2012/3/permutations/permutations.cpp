class Solution {
public:
    void findPermute(vector<int> &num, int depth, vector<vector<int> > &ans)
    {
        if(depth == num.size())
        {
            ans.push_back(num);
            return;
        }
        for(int i = depth; i < num.size(); ++ i)
        {
            swap(num[depth], num[i]);
            findPermute(num, depth + 1, ans);
            swap(num[depth], num[i]);
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
        findPermute(num, 0, ans);
        return ans;
    }
};