class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if(S.length() == 0 || L.empty())
            return ret;
        map<string, int> m;
        for(auto & s : L)
            ++ m[s];
        for(int i = 0; i <= (int)S.size() - (int)L.size() * (int)L[0].length(); ++ i) {
            map<string, int> cur_m;
            int j;
            for(j = 0; j < L.size(); ++ j) {
                string word = S.substr(i + j * L[0].length(), L[0].length());
                if(m.find(word) == m.end())
                    break;
                ++ cur_m[word];
                if(cur_m[word] > m[word])
                    break;
            }
            if(j == L.size())
                ret.push_back(i);
        }
        return ret;
    }
};