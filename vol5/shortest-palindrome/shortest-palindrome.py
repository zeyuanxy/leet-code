#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-19 20:43:07
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-19 20:43:21
class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        ss = s + '#' + s[::-1]
        n = len(ss)
        p = [0] * n
        for i in xrange(1, n):
            j = p[i - 1]
            while j > 0 and ss[i] != ss[j]:
                j = p[j - 1]
            p[i] = j + (ss[i] == s[j])
        return s[p[-1]:][::-1] + s 