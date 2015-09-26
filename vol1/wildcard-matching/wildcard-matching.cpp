class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *star = NULL, *ss = NULL;
        while(*s) {
            if(*p == '?' || *s == *p) {
                ++ s;
                ++ p;
                continue;
            }
            if(*p == '*') {
                star = p ++;
                ss = s;
                continue;
            }
            if(star) {
                p = star + 1;
                s = ++ ss;
                continue;
            }
            return false;
        }
        while(*p == '*')
            ++ p;
        return !*p;
    }
};