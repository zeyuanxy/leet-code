class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0 && index == -1) {
                index = i;
            } else if (nums[i] != 0 && index != -1) {
                nums[index] = nums[i];
                nums[i] = 0;
                ++index;
            }
        }
    }
};