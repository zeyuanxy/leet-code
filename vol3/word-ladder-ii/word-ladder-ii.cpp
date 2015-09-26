class Solution {
public:
    void bfs(string start, string end, unordered_set<string> &dict, unordered_map<string, int> &depth) {
        if(start == end)
            return;
        queue<string> q;
        q.push(start);
        depth[start] = 0;
        while(!q.empty()) {
            string s = q.front();
            q.pop();
            for(int i = 0; i < s.length(); ++ i)
                for(int j = 0; j < 26; ++ j) {
                    string t = s;
                    t[i] = 'a' + j;
                    if((t == end || dict.find(t) != dict.end()) && depth.find(t) == depth.end()) {
                        q.push(t);
                        depth[t] = depth[s] + 1;
                    }
                }
        }
    }
    
    void  dfs(string start, string end, unordered_set<string> &dict, unordered_map<string, int> &depth, vector<string> &path, vector<vector<string> > &ret) {
        if(start == end) {
            ret.push_back(path);
            return;
        }
        int goal = depth[start] - 1;
        for(int i = 0; i < start.length(); ++ i)
                for(int j = 0; j < 26; ++ j) {
                    string t = start;
                    t[i] = 'a' + j;
                    if(depth.find(t) != depth.end() && depth[t] == goal) {
                        path.push_back(t);
                        dfs(t, end, dict, depth, path, ret);
                        path.pop_back();
                    }
                }
    } 
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ret;
        if(start.length() == 0 || end.length() == 0)
            return ret;
        unordered_map<string, int> depth;
        bfs(start, end, dict, depth);
        vector<string> path;
        path.push_back(end);
        dfs(end, start, dict, depth, path, ret);
        for(auto & i : ret)
            reverse(i.begin(), i.end());
        return ret;
    }
};