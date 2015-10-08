class Solution {
public:
    void reverseWords(string &s) {
        string ans;
        for(int i = s.length() - 1; i >= 0; ) {
            while(i >= 0 && s[i] == ' ') 
                i --;
            if(i < 0) break;
            if(ans != "")
                ans += ' ';
            string t;
            while(i >= 0 && s[i] != ' ') 
                t = t + s[i --];
            reverse(t.begin(), t.end());
            ans += t;
        }
        s = ans;
    }
};