class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
            
        map<char, int> m;
        int ans = 1, start = 0;
        for(int i = 0; i < s.length(); ++ i) {
            if(m.find(s[i]) != m.end())
                start = max(start, m[s[i]] + 1);
            ans = max(ans, i - start + 1);
            m[s[i]] = i;
        }
        return ans;
    }
};