class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int r = -1, sum = 0, ans = nums.size() + 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0) {
                sum -= nums[i - 1];
            }
            while (sum < s && r + 1 < nums.size()) {
                ++r;
                sum += nums[r];
            }
            if (sum < s) {
                break;
            }
            ans = min(ans, r - i + 1);
        }
        if (ans == nums.size() + 1) {
            return 0;
        }
        return ans;
    }
};