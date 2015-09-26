class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> table;
        table.clear();
        for(int i = 0; i < num.size(); ++ i)
            table.insert(num[i]);
        int ans = 1;
        for(int i = 0; i < num.size(); ++ i) {
            set<int>::iterator iter;
            int temp = 0;
            for(int j = num[i]; ; -- j)
                if((iter = table.find(j)) != table.end()) {
                    temp ++;
                    table.erase(iter);
                }
                else
                    break;
            for(int j = num[i] + 1; ; ++ j)
                if((iter = table.find(j)) != table.end()) {
                    temp ++;
                    table.erase(iter);
                }
                else
                    break;
            ans = max(ans, temp);
        };
        return ans;
    }
};