class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL)
            return NULL;
        int len_h = strlen(haystack), len_n = strlen(needle);
        if(len_n == 0)
            return haystack;
        
        int *fail = new int[len_n];
        fail[0] = -1;
        int k = -1;
        for(int i = 1; i < len_n; ++ i) {
            while(k >= 0 && needle[i] != needle[k + 1])
                k = fail[k];
            if(needle[i] == needle[k + 1])
                k = k + 1;
            fail[i] = k;
        }
        
        int q = -1;
        for(int i = 0; i < len_h; ++ i) {
            while(q >= 0 && haystack[i] != needle[q + 1])
                q = fail[q];
            if(haystack[i] == needle[q + 1])
                q = q + 1;
            if(q == len_n - 1)
                return haystack + i - q;
        }
        
        return NULL;
    }
};