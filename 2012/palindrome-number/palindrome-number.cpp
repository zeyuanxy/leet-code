class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long long scale = 1;
        while(x > scale)
            scale *= 10;
        scale /= 10;
        while(x > 9) {
            int high = x / scale, low = x % 10;
            if(high != low)
                return false;
            x = (x % scale) / 10;
            scale /= 100;
        }
        return true;
    }
};