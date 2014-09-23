class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0)
            return "";
        int length = strs[0].length();
        for(int i = 1; i < strs.size(); ++ i) {
            for(int j = 0; j < length; ++ j)
                if(j >= strs[i].length() || strs[i][j] != strs[0][j]) {
                    length = j;
                    break;
                }
        }
        return strs[0].substr(0, length);
    }
};