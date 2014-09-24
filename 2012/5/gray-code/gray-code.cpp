class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if(n == 0)
        {
            ans.push_back(0);
            return ans;
        }
        if(n == 1)
        {
            ans.push_back(0);
            ans.push_back(1);
            return ans;
        }
        ans = grayCode(n - 1);
        for(int i = ans.size() - 1; i >= 0; -- i)
            ans.push_back(pow(2, n - 1) + ans[i]);
        return ans;
    }
};