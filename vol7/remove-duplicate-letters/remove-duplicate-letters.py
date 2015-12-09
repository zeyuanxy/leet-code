#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-12-09 13:38:18
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-12-09 13:38:32
import collections

class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        alphas = set(s)
        ans = ''
        for i in xrange(len(alphas)):
            first, index = s[0], 0
            counter = collections.Counter(s)
            for j in xrange(len(s)):
                if first > s[j]:
                    first, index = s[j], j
                if counter[s[j]] == 1:
                    break
                counter[s[j]] -= 1
            ans += first
            s = s[index + 1:].replace(first, '')
        return ans