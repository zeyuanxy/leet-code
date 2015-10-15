class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        nums = sorted(map(str, nums), cmp = lambda x, y: -1 if x + y > y + x else 1)
        return str(int(''.join(nums)))