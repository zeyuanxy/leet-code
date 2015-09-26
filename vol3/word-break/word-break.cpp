class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for(int i = 0; i <= s.length(); ++ i)
            for(int j = 0; j <= i - 1; ++ j)
                if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                        dp[i] = true;
                        break;
                }
        return dp[s.length()];
    }
};