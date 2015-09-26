class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<int, string> m_s;
        unordered_map<string, int> m_c;
        for(int i = 0; i < strs.size(); ++ i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m_s[i] = temp;
            if(m_c.find(temp) != m_c.end())
                ++ m_c[temp];
            else
                m_c[temp] = 1;
        }
        vector<string> ret;
        for(int i = 0; i < strs.size(); ++ i)
            if(m_c[m_s[i]] > 1)
                ret.push_back(strs[i]);
        return ret;
    }
};