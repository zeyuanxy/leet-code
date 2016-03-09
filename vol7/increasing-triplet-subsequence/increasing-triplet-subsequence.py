class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        first, second = None, None
        for num in nums:
            if first == None or first >= num:
                first = num
            elif second == None or second >= num:
                second = num
            else:
                return True
        return False
        