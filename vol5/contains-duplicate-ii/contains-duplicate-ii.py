class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        numIndex = {}
        for i in range(len(nums)):
            index = numIndex.get(nums[i], -k - 1)
            if i - index <= k:
                return True
            numIndex[nums[i]] = i
        return False