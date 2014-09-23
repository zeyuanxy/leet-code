class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        int i = len - 1, j = len - 1;
        for(i = len - 1; i >= 0; i --)
            if(s[i] != ' ')
                break;
        for(j = i; j >= 0; j --)
            if(s[j] == ' ')
                break;
        if(i > j)
            return i - j;
        else
            return 0;
    }
};