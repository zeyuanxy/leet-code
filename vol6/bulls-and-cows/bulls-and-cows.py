#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-10-30 20:10:42
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-10-30 20:10:47
class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        A = sum(map(lambda (a, b): 1 if a == b else 0, zip(secret, guess)))
        m1, m2 = {}, {}
        for c in secret:
            m1[c] = m1.get(c, 0) + 1
        for c in guess:
            m2[c] = m2.get(c, 0) + 1
        B = sum(min(v, m2.get(c, 0)) for c, v in m1.iteritems()) - A
        return '{}A{}B'.format(A, B)