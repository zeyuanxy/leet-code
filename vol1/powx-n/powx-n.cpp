class Solution {
public:
    double pow(double x, int n) {
        if(x == 1)
            return 1;
        if(x == -1)
            return (n % 2 == 0)? 1 : -1; 
        if(n == 0)
            return 1;
        if(n < 0)
            return 1 / pow(x, -n);
        double ans = pow(x, n / 2);
        if(n % 2 == 0)
            return ans * ans;
        else
            return ans * ans * x;
    }
};