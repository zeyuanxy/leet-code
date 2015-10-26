class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if len(nums) == 0:
            return nums
        ret = []
        for num in nums:
            if len(ret) == 0 or ret[-1][-1] + 1 < num:
                ret.append([num, num])
            else:
                ret[-1][-1] = num
        ret = map(lambda x: str(x[0]) if x[0] == x[1] else '{}->{}'.format(x[0], x[1]), ret)
        return ret