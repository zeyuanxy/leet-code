class Solution {
public:
    string simplifyPath(string path) {
        vector<string> p;
        int i = 0;
        while(i < path.length()) {
            while(i < path.length() && path[i] == '/')
                ++ i;
            int j = i + 1;
            while(j < path.length() && path[j] != '/')
                ++ j;
            string s = path.substr(i, j - i);
            if(s == "")
                break;
            p.push_back(s);
            if(s.length() <= 2 && s[0] == '.') {
                p.pop_back();
                if(s.length() == 2 && s[1] == '.' && !p.empty())
                    p.pop_back();
            }
            i = j + 1;
        }
        string ret = "";
        for(int i = 0; i < p.size(); ++ i)
            ret = ret + "/" + p[i];
        return ret == "" ? "/" : ret;
    }
};