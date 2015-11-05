#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-05 00:08:08
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-05 00:08:20
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0
        n, m = len(matrix), len(matrix[0])
        dp = [[0] * m for i in xrange(n)]
        ans = 0
        for i in xrange(n):
            for j in xrange(m):
                dp[i][j] = int(matrix[i][j])
                if i > 0 and j > 0 and dp[i][j]:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                ans = max(ans, dp[i][j])
        return ans * ans