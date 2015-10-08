class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if(num.size() < 4)
            return ret;
        
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 3; ++ i) {
            if(i > 0 && num[i] == num[i - 1])
                continue;
            for(int j = i + 1; j < num.size() - 2; ++ j) {
                if(j > i + 1 && num[j] == num[j - 1])
                    continue;
                int k = j + 1, t = num.size() - 1;
                while(k < t) {
                    if(k > j + 1 && num[k] == num[k - 1]) {
                        ++ k;
                        continue;
                    }
                    if(t < num.size() - 1 && num[t] == num[t + 1]) {
                        -- t;
                        continue;
                    }
                    int sum = num[i] + num[j] + num[k] + num[t];
                    if(sum == target) {
                        vector<int> temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[j]);
                        temp.push_back(num[k]);
                        temp.push_back(num[t]);
                        ret.push_back(temp);
                        ++ k;
                    }
                    else if(sum < target)
                        ++ k;
                    else
                        -- t;
                }
            }
        }
        return ret;
    }
};