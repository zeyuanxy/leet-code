class Solution {
public:
    string minWindow(string S, string T) {
        map<char, int> t_map;
        map<char, int> s_map;
        for(int i = 0; i < T.length(); ++ i) {
            if(t_map.find(T[i]) != t_map.end())
                ++ t_map[T[i]];
            else
                t_map[T[i]] = 1;
            s_map[T[i]] = 0;
        }
        int sum = 0, start = 0, end = 0;
        for(end = 0; end < S.length(); ++ end)
            if(t_map.find(S[end]) != t_map.end()) {
                ++ s_map[S[end]];
                if(s_map[S[end]] == t_map[S[end]])
                    sum ++;
                if(sum == t_map.size())
                    break;
            }
        if(sum != t_map.size())
            return "";
        for(; start < end; ++ start)
            if(t_map.find(S[start]) != t_map.end()) {
                if(s_map[S[start]] == t_map[S[start]])
                    break;
                -- s_map[S[start]];
            }
        int ans = end - start + 1, ans_start = start;
        end += 1;
        for(; end < S.length(); ++ end)
            if(t_map.find(S[end]) != t_map.end()) {
                ++ s_map[S[end]];
                for(; start < end; ++ start)
                if(t_map.find(S[start]) != t_map.end()) {
                    if(s_map[S[start]] == t_map[S[start]])
                        break;
                    -- s_map[S[start]];
                }
                if(ans > end - start + 1) {
                    ans = end - start + 1;
                    ans_start = start;
                }
            }
        return S.substr(ans_start, ans);
    }
};