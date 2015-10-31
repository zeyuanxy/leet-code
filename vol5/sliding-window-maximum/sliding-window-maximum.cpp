/* 
* @Author: Zeyuan Shang
* @Date:   2015-10-31 16:56:16
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2015-10-31 16:56:28
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.empty()) {
            return ret;
        }
        deque<int> dq;
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ret.push_back(dq.front());
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i - k] == dq.front()) {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ret.push_back(dq.front());
        }
        return ret;
    }
};