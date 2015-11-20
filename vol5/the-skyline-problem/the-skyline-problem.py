#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-20 02:04:58
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-20 02:05:05
import heapq

class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        if not buildings:
            return []
        n = len(buildings)
        ranges = []
        for i in xrange(n):
            ranges.append([buildings[i][0], i, 1])
            ranges.append([buildings[i][1], i, -1])
        ranges = sorted(ranges)
        
        inRange = {}
        heap = []
        ans = []
        for idx in xrange(2 * n):
            r, i, e = ranges[idx]
            if e > 0:
                inRange[i] = True
                heapq.heappush(heap, [-buildings[i][2], i])
            else:
                inRange[i] = False
            if idx + 1 < 2 * n and r == ranges[idx + 1][0]:
                continue
            heapTop = heapq.heappop(heap)
            while heap and not inRange[heapTop[1]]:
                heapTop = heapq.heappop(heap)
            if inRange[heapTop[1]]:
                heapq.heappush(heap, heapTop)
                newHeight = -heapTop[0]
            else:
                newHeight = 0
            while ans and ans[-1][0] == r and ans[-1][1] < newHeight:
                ans = ans[:-1]
            if not ans or ans[-1][1] != newHeight:
                ans.append([r, newHeight])
        return ans