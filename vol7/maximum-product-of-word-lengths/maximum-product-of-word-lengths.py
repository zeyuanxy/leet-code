#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-12-18 19:16:17
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-12-18 19:16:23
class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        nums = []
        for word in words:
            nums.append(sum(1 << (ord(x) - ord('a')) for x in set(word)))
        ans = 0
        for x in xrange(len(nums)):
            for y in xrange(len(nums)):
                if nums[x] & nums[y] == 0:
                    ans = max(ans, len(words[x]) * len(words[y]))
        return ans