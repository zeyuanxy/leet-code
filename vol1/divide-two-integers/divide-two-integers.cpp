class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long long a = abs((long long)dividend), b = abs((long long)divisor);
        int ans = 0;
        while(a >= b) {
            int count = 1;
            long long temp = abs((long long)divisor);
            while(a >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            a -= temp;
            ans += count;
        }
        
        return (isNegative ? -ans : ans);
    }
};