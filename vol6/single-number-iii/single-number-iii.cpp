class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_res = 0;
        for (auto num : nums) {
            xor_res ^= num;
        }
        int n = xor_res & (~(xor_res - 1));
        vector<int> ret(2, 0);
        for (auto num : nums) {
            if (num & n) {
                ret[0] ^= num;
            } else {
                ret[1] ^= num;
            }
        }
        return ret;
    }
};