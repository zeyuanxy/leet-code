#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-04 00:19:51
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-04 00:20:00
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = []
        for num in nums:
            l, r = 0, len(dp) - 1
            while l <= r:
                mid = (l + r) / 2
                if dp[mid] < num:
                    l = mid + 1
                else:
                    r = mid - 1
            if l == len(dp):
                dp.append(num)
            else:
                dp[l] = num
        return len(dp)