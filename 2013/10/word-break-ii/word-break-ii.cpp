class Solution {
public:
    void search(string s, string temp, vector<string> &ret, unordered_set<string> &dict) {
        if(s.size() == 0) {
            ret.push_back(temp);
            return;
        }
        
        for(auto & i : dict)
            if(i.length() <= s.length() && s.substr(s.length() - i.length()) == i)
                search(s.substr(0, s.length() - i.length()), i + " " + temp, ret, dict);
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ret;
        if(s.size() == 0 || dict.empty())
            return ret;
        
        for(auto & i : dict)
            if(i.length() <= s.length() && s.substr(s.length() - i.length()) == i)
                search(s.substr(0, s.length() - i.length()), i, ret, dict);
    }
};