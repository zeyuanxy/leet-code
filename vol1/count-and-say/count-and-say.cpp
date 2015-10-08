class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; ++ i) {
            char last = ans[0];
            int count = 1;
            stringstream s;
            for(int j = 1; j < ans.length(); ++ j)
                if(ans[j] == last)
                    count ++;
                else {
                    s << count << last;
                    last = ans[j];
                    count = 1;
                }

            s << count << last;
            ans = s.str();
        }
        return ans;
    }
};