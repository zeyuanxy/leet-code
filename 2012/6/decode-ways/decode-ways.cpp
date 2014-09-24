class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0)
            return 0;
        int f[s.length() + 1];
        f[0] = 1;
        for(int i = 1; i <= s.length(); ++ i) {
            f[i] = 0;
            if(s[i - 1] >= '1' && s[i - 1] <= '9')
                f[i] += f[i - 1];
            if(i > 1 && atoi(s.substr(i - 2, 2).c_str()) <= 26 && atoi(s.substr(i - 2, 2).c_str()) >= 10)
                f[i] += f[i - 2];
        }
        return f[s.length()];
    }
};