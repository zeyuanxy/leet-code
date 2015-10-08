class Solution {
public:
    int numDistinct(string S, string T) {
        int f[S.length() + 1][T.length() + 1];
        memset(f, 0, sizeof(int) * (S.length() + 1) * (T.length() + 1));
        for(int i = 0; i <= S.length(); ++ i)
            f[i][0] = 1;
        for(int i = 1; i <= S.length(); ++ i)
            for(int j = 1; j <= T.length(); ++ j)
                if(S[i - 1] == T[j - 1])
                    f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
                else
                    f[i][j] = f[i - 1][j];
        return f[S.length()][T.length()];
    }
};