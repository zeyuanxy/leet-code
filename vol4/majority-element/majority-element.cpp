class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = 0, count = 0;
        for (auto num : nums) {
            if (count == 0) {
                ret = num;
                count = 1;
            } else if (ret == num) {
                ++count;
            } else {
                --count;
            }
        }
        return ret;
    }
};