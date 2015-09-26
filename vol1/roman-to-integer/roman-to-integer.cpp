class Solution {
public:
    int getRomanValue(char c){
        switch(c)
        {
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L': return 50;  
            case 'C': return 100;  
            case 'D': return 500;  
            case 'M': return 1000;  
            default: return 0;
        };
    }
    
    int romanToInt(string s) {
        if(s.length() == 0)
            return 0;
        int ans = 0, temp = getRomanValue(s[0]);
        int curValue, lastValue = temp;
        for(int i = 1; i < s.length(); ++ i)
        {
            curValue = getRomanValue(s[i]);
            if(curValue == lastValue)
                temp += getRomanValue(s[i]);
            if(curValue > lastValue)
                temp = getRomanValue(s[i]) - temp;
            if(curValue < lastValue)
            {
                ans += temp;
                temp = getRomanValue(s[i]);
            }
            lastValue = curValue;
        } 
        return ans + temp;
    }
};