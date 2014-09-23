class Solution {
public:
    int reverse(int x) {
        int symbol = 1;
        if(x < 0)
        {
            x = -x;
            symbol = -1;
        }
        long y = 0;
        while(x != 0)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }
        if(y > INT_MAX)
            return -1;
        return symbol * y;
    }
};