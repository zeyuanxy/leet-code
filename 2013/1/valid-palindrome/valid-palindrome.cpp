class Solution {
public:
    bool isAlphaOrNumber(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' & c <= 'Z') || (c >= '0' && c <= '9')); 
    }
    void toUpper(char &c)
    {
        if(c >= 'a' && c <= 'z')
            c = c - 'a' + 'A';
    }

    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        
        int l = 0, r = s.length() - 1;
        while(l < r)
        {
            while(l < s.length() && !isAlphaOrNumber(s[l]))
                l ++;
            while(r >= 0 && !isAlphaOrNumber(s[r]))
                r --;
            if(l >= r)
                break;
            toUpper(s[l]);
            toUpper(s[r]);
            if(s[l] != s[r])
                return false;
            else {
                l ++;
                r --;
            }
        }
        
        return true;
    }
};