class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        def simple_rob(nums):
            if not nums:
                return 0
            rob_last, not_rob_last = 0, 0
            for num in nums:
                rob_last, not_rob_last = max(rob_last, not_rob_last + num), rob_last
            return max(rob_last, not_rob_last)
        
        return max(simple_rob(nums[1:]), simple_rob(nums[:-1]))
        