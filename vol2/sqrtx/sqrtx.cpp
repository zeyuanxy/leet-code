class Solution {
public:
    int sqrt(int x) {
        if(x < 0)
            return -1;
        double y = x;
        while(abs(y * y - x) > 0.001)
            y = (y + x / y) / 2;
        return (int)y;
    }
};