class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        import random
        pivot = random.choice(nums)
        left, right = [], []
        for num in nums:
            if num < pivot:
                left.append(num)
            elif num > pivot:
                right.append(num)
        if len(right) >= k:
            return self.findKthLargest(right, k)
        if len(nums) - len(left) < k:
            return self.findKthLargest(left, k - (len(nums) - len(left)))
        return pivot
        