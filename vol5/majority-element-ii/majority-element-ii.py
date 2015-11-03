#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-02 22:14:38
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-02 22:14:46
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        num1, cnt1 = None, 0
        num2, cnt2 = None, 0
        for num in nums:
            if num == num1:
                cnt1 += 1
            elif num == num2:
                cnt2 += 1
            elif cnt1 == 0:
                num1 = num
                cnt1 = 1
            elif cnt2 == 0:
                num2 = num
                cnt2 = 1
            else:
                cnt1 -= 1
                cnt2 -= 1
        return filter(lambda n: nums.count(n) > len(nums) / 3, [num1, num2])