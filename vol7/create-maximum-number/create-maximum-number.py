#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2016-01-05 10:01:17
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2016-01-05 10:01:27
class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        def getMaxNumber(nums, t):
            ans = []
            n = len(nums)
            for x in xrange(n):
                while ans and len(ans) + n - x > t and ans[-1] < nums[x]:
                    ans.pop()
                if len(ans) < t:
                    ans.append(nums[x])
            return ans
            
        def merge(nums1, nums2):
            return [max(nums1, nums2).pop(0) for _ in nums1 + nums2]
        
        n = len(nums1)
        m = len(nums2)
        ans = []
        for t in xrange(max(0, k - m), min(k, n) + 1):
            ans = max(ans, merge(getMaxNumber(nums1, t), getMaxNumber(nums2, k - t)))
        return ans