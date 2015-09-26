class Solution {
public:
    bool isNumber(const char *s) {
        int start = 0, end = 0;
        int len = strlen(s), ePos = -1, pPos = -1;
        for(start = 0; start < len; ++ start)
            if(s[start] != ' ')
                break;
        for(end = len - 1; end >= 0; -- end)
            if(s[end] != ' ')
                break;
        if(s[start] == '-' || s[start] == '+')
            ++ start;
        bool flag = false;
        for(int i = start; i <= end; ++ i)
            if(!isdigit(s[i])) {
                if(s[i] == 'e' && ePos == -1)
                    ePos = i;
                else if(s[i] == '.' && pPos == -1)
                    pPos = i;
                else if((s[i] == '+' || s[i] == '-') && ePos == i - 1 && i < end)
                    ;
                else
                    return false;
            }
            else 
                flag = true;
        if(!flag)
            return false;
        if(ePos >= start) {
            if(ePos == start || (!isdigit(s[ePos - 1]) && s[ePos - 1] != '.'))
                return false;
            if(ePos + 1 > end || (!isdigit(s[ePos + 1]) && s[ePos + 1] != '.' && s[ePos + 1] != '+' && s[ePos + 1] != '-'))
                return false;
        }
        if(pPos >= start) {
            if(pPos > start && !isdigit(s[pPos - 1]) && s[pPos - 1] != 'e')
                return false;
            if(pPos < end && !isdigit(s[pPos + 1]) && s[pPos + 1] != 'e')
                return false;
            if(pPos == start && ePos == pPos + 1)
                return false;
            if(pPos == end && ePos == pPos - 1)
                return false;
        }
        if(ePos >= 0 && pPos > ePos)
            return false;
        return true;
    }
};