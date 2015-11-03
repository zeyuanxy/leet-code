#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-02 22:24:39
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-02 22:24:46
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        arr = [1]
        i2, i3, i5 = 0, 0, 0
        while len(arr) < n:
            u2, u3, u5 = arr[i2] * 2, arr[i3] * 3, arr[i5] * 5
            u = min(u2, u3, u5)
            if u == u2:
                i2 += 1
            if u == u3:
                i3 += 1
            if u == u5:
                i5 += 1
            arr.append(u)
        return arr[-1]
        