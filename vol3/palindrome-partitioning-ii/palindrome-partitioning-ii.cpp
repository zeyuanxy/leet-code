class Solution {
public:
    int minCut(string s) {
        int f[s.length()];
        f[0] = 0;
        bool p[s.length()][s.length()];
        memset(p, false, sizeof(bool) * s.length() * s.length());
        for(int k = 0; k < s.length(); ++ k)
            for(int i = 0; i < s.length() - k; ++ i) {
                p[i][i + k] =(s[i] == s[i + k]);
                if(k > 1)
                    p[i][i + k] = (p[i][i + k] && p[i + 1][i + k - 1]);
            }
        for(int i = 1; i < s.length(); ++ i) {
            f[i] = 0;
            if(!p[0][i]) {
                f[i] = s.length() + 1;
                for(int j =  0; j < i; ++ j)
                    if(p[j + 1][i])
                        f[i] = min(f[i], f[j] + 1);
            }
        }
        return f[s.length() - 1];
    }
};