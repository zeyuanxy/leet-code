class Solution {
public:
    vector<vector<int> > findSum(vector<int> &candidates, int target, int maxValue) {
        vector<vector<int> > ans;
        if(target == 0) {
            vector<int> temp;
            ans.push_back(temp);
            return ans;
        }
        
        for(int i = 0; i < candidates.size(); ++ i) 
            if(candidates[i] <= maxValue) {
                vector<vector<int> > part = findSum(candidates, target - candidates[i], min(candidates[i], target - candidates[i]));
                for(int j = 0; j < part.size(); ++ j) {
                    part[j].push_back(candidates[i]);
                    ans.push_back(part[j]);
                }
            }
            else
                break;
        return ans;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return findSum(candidates, target, target);
    }
};