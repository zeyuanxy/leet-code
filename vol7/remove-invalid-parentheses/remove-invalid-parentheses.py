#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-23 13:57:44
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-23 13:58:39
class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def calc(s):
            left = 0
            right = 0
            for c in s:
                if c == '(':
                    left += 1
                elif c == ')':
                    if left == 0:
                        right += 1
                    else:
                        left -= 1
            return left + right
        
        def dfs(s):
            n = calc(s)
            if n == 0:
                return [s]
            ans = []
            for i in xrange(len(s)):
                if s[i] in ['(', ')']:
                    ss = s[:i] + s[i + 1:]
                    if ss not in visited and calc(ss) < n:
                        visited.add(ss)
                        ans.extend(dfs(ss))
            return ans
            
        visited = set([s])
        return dfs(s)