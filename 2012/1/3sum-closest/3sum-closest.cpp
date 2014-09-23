class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size() < 3)
            return -1;
        int ans = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        for(int i = 0; i <= num.size() - 3; ++ i) {
            int l = i + 1, r = num.size() - 1;
            while(l < r) {
                int sum = num[i] + num[l] + num[r];
                if(sum == target)
                    return target;
                if(sum < target)
                    ++ l;
                else
                    -- r;
                if(abs(sum - target) < abs(ans - target))
                    ans = sum;
            }
        }
        return ans;
    }
};