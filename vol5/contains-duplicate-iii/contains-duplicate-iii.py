#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-03 15:38:09
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-03 15:38:18
import collections

class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        numDict = collections.OrderedDict()
        for i, num in enumerate(nums):
            key = num / max(t, 1)
            for j in [key - 1, key, key + 1]:
                if j in numDict and abs(numDict[j] - num) <= t:
                    return True
            numDict[key] = num
            if i >= k:
                numDict.popitem(last = False)
        return False
        