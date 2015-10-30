class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        int ans = m;
        while (true) {
            long long r = (1ULL << i) - (m & ((1ULL << i) - 1));
            if (m + r > n) {
                break;
            }
            ans &= ~(1 << i);
            i++;
        }
        return ans;
    }
};