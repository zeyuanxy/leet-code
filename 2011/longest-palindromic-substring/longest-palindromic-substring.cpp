class Solution {
public:
    string getLongestPalindrome(string s, int l, int r) {
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            -- l;
            ++ r;
        }
        return s.substr(l + 1, r - l - 1);
    }

    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        string ans = "";
        for(int i = 0; i < s.length(); ++ i) {
            string temp = getLongestPalindrome(s, i, i);
            if(temp.length() > ans.length())
                ans = temp;
            temp = getLongestPalindrome(s, i, i + 1);
            if(temp.length() > ans.length())
                ans = temp;
        }
        return ans;
    }
};