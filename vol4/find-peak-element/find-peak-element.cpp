class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid == 0 || nums[mid] > nums[mid - 1]) {
                if (mid + 1 == nums.size() || nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};