class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1 + l2 != l3)
            return false;
        bool f[l3 + 1][l1 + 1][l2 + 1];
        memset(f, false, sizeof(bool) * (l3 + 1) * (l1 + 1) * (l2 + 1));
        f[0][0][0] = true;
        for(int i = 1; i <= l3; ++ i)
            for(int j = max(0, i - l2); j <= min(i, l1); ++ j) {
                int k = i - j;
                if(j > 0 && f[i - 1][j - 1][k] && s3[i - 1] == s1[j - 1])
                    f[i][j][k] = true;
                if(k > 0 && f[i - 1][j][k - 1] && s3[i - 1] == s2[k - 1])
                    f[i][j][k] = true;
            }
        return f[l3][l1][l2];
    }
};