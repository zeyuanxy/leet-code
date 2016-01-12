#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2016-01-12 18:38:36
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2016-01-12 18:38:44
class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n > 0 and 3 ** round(math.log(n, 3)) == n