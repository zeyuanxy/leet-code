class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end)
            return 0;
        queue<string> q;
        q.push(start);
        unordered_map<string, int> in_q;
        in_q[start] = 1;
        while(!q.empty()) {
            string s = q.front();
            q.pop();
            for(int i = 0; i < s.length(); ++ i)
                for(int j = 0; j < 26; ++ j) {
                    string t = s;
                    t[i] = 'a' + j;
                    if(t == end) 
                        return in_q[s] + 1;
                    if(dict.find(t) != dict.end() && in_q.find(t) == in_q.end()) {
                        q.push(t);
                        in_q[t] = in_q[s] + 1;
                    }
                }
        }
        return 0;
    }
};