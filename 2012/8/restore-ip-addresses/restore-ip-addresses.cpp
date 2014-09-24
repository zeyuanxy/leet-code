class Solution {
public:
    bool check(string &s) {
        if(s.length() == 0)
            return false;
        if(s.length() == 1)
            return true;
        if(s[0] == '0')
            return false;
        int t = atoi(s.c_str());
        if(t <= 255)
            return true;
        return false;
    }

    void dfs(int depth, string ans, string s, vector<string> &ret) {
        if(depth == 3) {
            if(check(s))
                ret.push_back(ans + s);
            return;
        };
        
        for(int i = 1; i <= min(3, (int)s.length()); ++ i) {
            string sub = s.substr(0, i);
            if(check(sub))
                dfs(depth + 1, ans + sub + ".", s.substr(i, s.length() - i), ret);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        dfs(0, "", s, ret);
        return ret;
    }
};