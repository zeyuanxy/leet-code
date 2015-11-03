#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-03 15:21:00
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-03 15:21:14
import itertools

class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 0:
            return 0
        def digits(n):
            while n:
                yield n % 10
                n /= 10
        def pows(b):
            x = 1
            while True:
                yield x
                x *= 10
        def g(d, m):
            if d < 1:
                return n / (m * 10) * m
            elif d == 1:
                return n / (m * 10) * m + n % m + 1
            else:
                return (n / (m * 10) + 1) * m
        return sum(itertools.starmap(g, itertools.izip(digits(n), pows(10))))