class Solution {
public:
    string getPermutation(int n, int k) {
        long long count = 1;
        int num[n];
        for(int i = 0; i < n; ++ i) {
            num[i] = i + 1;
            count *= i + 1;
        }
        string ret = "";
        -- k;
        for(int i = 0; i < n; ++ i) {
            count /= (n - i);
            int selected = k / count;
            ret += ('0' + num[selected]);
            for(int j = selected; j < n; ++ j)
                num[j] = num[j + 1];
            k = k % count;
        }
        return ret;
    }
};