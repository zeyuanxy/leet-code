class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int start = 0, end = 0;
        vector<string> ans;
        while(start < words.size()) {
            int total = words[start].length(), space = 0, offset = 0;
            ++ end;
            while(end < words.size() && total + 1 + words[end].length() <= L) {
                total += 1 + words[end].length();
                ++ end;
            }
            if(end != start + 1) {
                space = 1 + (L - total) / (end - start - 1);
                offset = (L - total) % (end - start - 1);
            }
            else {
                space = L - total;
                offset = 0;
            }
            if(end == words.size()) {
                space = 1;
                offset = 0;
            }
            string res = "";
            for(int i = start; i < end; ++ i) {
                res.append(words[i]);
                int num = (i - start < offset) ? space + 1 : space;
                if(res.length() < L)
                    res.append(num, ' ');
            }
            if(res.length() < L)
                res.append(L - res.length(), ' ');
            ans.push_back(res);
            start = end;
        }
        return ans;
    }
};