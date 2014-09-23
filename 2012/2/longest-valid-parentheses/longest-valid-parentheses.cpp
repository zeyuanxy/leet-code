class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0)
            return 0;
            
        stack<int> p;
        int *f = new int[s.length()];
        memset(f, 0, sizeof(int) * s.length());
        int ans = 0;
        for(int i = 0; i < s.length(); ++ i)
            if(s[i] == '(')
                p.push(i);
            else if(!p.empty()) {
                if(p.top() > 0)
                    f[i] = f[p.top() - 1] + i - p.top() + 1;
                else
                    f[i] = i + 1;
                ans = max(ans, f[i]);
                p.pop();
            }
        return ans;
    }
};