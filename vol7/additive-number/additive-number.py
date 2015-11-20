#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-19 22:47:10
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-19 22:47:21
class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        if not num:
            return False
        def check(a, b, s):
            while s != '':
                c = str(a + b)
                if not s.startswith(c):
                    return False
                s = s[len(c):]
                a = b
                b = int(c)
            return True
            
        n = len(num)
        for i in xrange(1, n - 1):
            for j in range(i + 1, n):
                a = int(num[:i])
                b = int(num[i:j])
                if b != 0 and num[i] == '0':
                    continue
                if check(a, b, num[j:]):
                    return True
        return False