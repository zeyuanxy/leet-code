#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-19 21:10:01
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-19 21:10:09
class NumMatrix(object):
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        if not matrix:
            return
        n, m = len(matrix), len(matrix[0])
        self.sums = [[0] * (m + 1)]
        for i in xrange(1, n + 1):
            self.sums.append([0] * (m + 1))
            for j in range(1, m + 1):
                self.sums[i][j] = self.sums[i][j - 1] + self.sums[i - 1][j] - self.sums[i - 1][j - 1] + matrix[i - 1][j - 1]
        		

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        return self.sums[row2 + 1][col2 + 1] - self.sums[row1][col2 + 1] - self.sums[row2 + 1][col1] + self.sums[row1][col1]
  

# Your NumMatrix object will be instantiated and called as such:
# numMatrix = NumMatrix(matrix)
# numMatrix.sumRegion(0, 1, 2, 3)
# numMatrix.sumRegion(1, 2, 3, 4)