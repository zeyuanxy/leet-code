class Solution {
public:
    int atoi(const char *str) {
        int length = strlen(str);
        if(length == 0)
            return 0;
            
        int i = 0;
        for(; i < length; ++ i)
            if(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
                break;
            else
                if(str[i] != ' ')
                    return 0;
        bool isPositive = true;
        if(str[i] == '+')
            ++ i;
        if(str[i] == '-') {
            isPositive = false;
            ++ i;
        }
        
        long long ans = 0;
        for(; i < length; ++ i)
            if(str[i] >= '0' && str[i] <= '9')
                ans = ans * 10 + str[i] - '0';
            else
                break;
        if(!isPositive)
            ans = -ans;
        if(ans < -2147483648)
            return -2147483648;
        else if(ans > 2147483647)
            return 2147483647;
        else
            return (int)ans;
    }
};