class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int rob_last = nums[0], not_rob_last = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int rob = max(rob_last, not_rob_last + nums[i]);
            not_rob_last = rob_last;
            rob_last = rob;
        }
        return max(rob_last, not_rob_last);
    }
};