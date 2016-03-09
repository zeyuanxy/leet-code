# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2016-03-09 22:56:44
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2016-03-09 22:56:54
class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        index, right, ans = 0, 1, 0
        size = len(nums)
        sorted_nums = sorted(nums)
        while right <= n:
            if index < size and sorted_nums[index] <= right:
                right += sorted_nums[index]
                index += 1
            else:
                right <<= 1
                ans += 1
        return ans
        