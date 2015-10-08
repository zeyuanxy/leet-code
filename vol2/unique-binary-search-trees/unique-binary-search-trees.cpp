class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 1;
        long long ans = 0;
        for(int i = 1; i <= n; ++ i)
            ans += numTrees(i - 1) * numTrees(n - i);
        return ans;
    }
};