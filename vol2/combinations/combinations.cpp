class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ans, temp;
        if(k == 0)
        {
            vector<int> com;
            ans.push_back(com);
            return ans;
        }
        if(n == k)
        {
            vector<int> com;
            for(int i = 1; i <= n; ++ i)
                com.push_back(i);
            ans.push_back(com);
            return ans;
        }
        ans = combine(n - 1, k);
        temp = combine(n - 1, k - 1);
        for(int i = 0; i < temp.size(); ++ i)
        {
            temp[i].push_back(n);
            ans.push_back(temp[i]);
        }
        return ans;
    }
};