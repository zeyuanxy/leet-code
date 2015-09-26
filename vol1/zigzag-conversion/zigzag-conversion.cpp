class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1)
            return s;
        
        string ans = "";
        for(int i = 0; i < nRows; ++ i) {
            int j = i;
            while(j < s.length()) {
                ans += s[j];
                if(i != 0 && i != nRows - 1 && j + 2 *(nRows - i - 1) < s.length())
                    ans += s[j + 2 * (nRows - i - 1)];
                j += 2 * (nRows - 1);
            }
        }
        return ans;
    }
};