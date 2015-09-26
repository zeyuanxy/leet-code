class Solution {
public:
    void search(vector<int> &num, int prev, vector<int> &temp, int left, vector<vector<int> > &ret) {
        if(left == 0) {
            ret.push_back(temp);
            return;
        }
        
        for(int i = prev + 1; i < num.size(); ++ i)
            if(num[i] <= left && (i == prev + 1 || (i > prev + 1 && num[i] != num[i - 1]))) {
                temp.push_back(num[i]);
                search(num, i, temp, left - num[i], ret);
                temp.pop_back();
            }
            else if(num[i] > left)
                break;
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if(num.empty())
            return ret;
        
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++ i)
            if(num[i] <= target && ((i == 0) || (i > 0 && num[i] != num[i - 1]))) {
                vector<int> temp;
                temp.push_back(num[i]);
                search(num, i, temp, target - num[i], ret);
                temp.pop_back();
            }
        return ret;
    }
};