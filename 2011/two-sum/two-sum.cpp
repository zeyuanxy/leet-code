class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        map<int, int> m;
        for(int i = 0; i < numbers.size(); ++ i) {
            if(m.find(target - numbers[i]) != m.end())
            {
                ans.push_back(m[target - numbers[i]]);
                ans.push_back(i + 1);
            }
            if(m.find(numbers[i]) == m.end())
                m[numbers[i]] = i + 1;
        }
        return ans;
    }
};