#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-18 17:42:12
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-18 17:42:18
class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        n = len(dungeon)
        m = len(dungeon[0])
        dp = [sys.maxint] * m
        dp[-1] = max(-dungeon[n - 1][m - 1], 0) + 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if i + 1 < n:
                    dp[j] = max(dp[j] - dungeon[i][j], 1)
                    if j + 1 < m:
                        dp[j] = min(dp[j], max(dp[j + 1] - dungeon[i][j], 1))
                elif j + 1 < m:
                    dp[j] = max(dp[j + 1] - dungeon[i][j], 1)
        return dp[0]
        