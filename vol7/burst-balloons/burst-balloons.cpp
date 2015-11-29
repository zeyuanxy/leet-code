/* 
* @Author: Zeyuan Shang
* @Date:   2015-11-29 16:03:58
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2015-11-29 16:04:06
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> num(n + 2);
        num[0] = 1;
        for (int i = 1; i <= n; ++i) {
            num[i] = nums[i - 1];
        }
        num[n + 1] = 1;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int length = 1; length <= n; ++length) {
            for (int i = 1; i <= n - length + 1; ++i) {
                int j = i + length - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + num[i - 1] * num[k] * num[j + 1]);
                }
            }
        }
        return dp[1][n];
    }
};