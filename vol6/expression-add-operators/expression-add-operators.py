#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-24 02:03:32
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-24 02:03:44
class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        def dfs(num, target, expr = '', val = 1):
            ans = []
            if (num == '0' or num[0] != '0') and (int(num) * val == target):
                ans.append(num + expr)
            for i in range(len(num) - 1):
                left_num, right_num = num[:i + 1], num[i + 1:]
                if right_num == '0' or right_num[0] != '0':
                    right, rightVal = right_num + expr, int(right_num) * val
                    for left in dfs(left_num, target - rightVal):
                        ans.append(left + '+' + right)
                    for left in dfs(left_num, target + rightVal):
                        ans.append(left + '-' + right)
                    for left in dfs(left_num, target, '*' + right, rightVal):
                        ans.append(left)
            return ans
        if not num:
            return []
        return dfs(num, target)