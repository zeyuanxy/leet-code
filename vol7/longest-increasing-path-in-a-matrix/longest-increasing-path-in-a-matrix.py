# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2016-03-09 22:44:39
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2016-03-09 22:44:45
class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        n = len(matrix)
        if n == 0:
            return 0
        m = len(matrix[0])
        
        def dfs(x, y):
            dp[x][y] = 1
            for dx, dy in zip([1, 0, -1, 0], [0, 1, 0, -1]):
                xx, yy = x + dx, y + dy
                if xx >= 0 and xx < n and yy >= 0 and yy < m and matrix[xx][yy] > matrix[x][y]:
                    if dp[xx][yy] == 0:
                        dp[xx][yy] = dfs(xx, yy)
                    dp[x][y] = max(dp[x][y], dp[xx][yy] + 1)
            return dp[x][y]
        
        dp = [[0] * m for i in xrange(n)]
        for x in xrange(n):
            for y in xrange(m):
                dp[x][y] = dfs(x, y)
        return max([max(x) for x in dp])
        