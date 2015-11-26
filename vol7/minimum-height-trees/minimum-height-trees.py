#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-26 00:05:52
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-26 00:05:58
class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        adj_list = []
        for i in xrange(n):
            adj_list.append([])
        for edge in edges:
            adj_list[edge[0]].append(edge[1])
            adj_list[edge[1]].append(edge[0])
        print adj_list
        
        queue = [0]
        visited = [False] * n
        visited[0] = True
        start = 0
        while queue:
            x, queue = queue[0], queue[1:]
            for y in adj_list[x]:
                if not visited[y]:
                    queue.append(y)
                    visited[y] = True
                    start = y
        
        queue = [start]
        prev = [-1] * n
        end = 0
        while queue:
            x, queue = queue[0], queue[1:]
            for y in adj_list[x]:
                if prev[y] == -1 and y != start:
                    queue.append(y)
                    prev[y] = x
                    end = y
                    
        path = [end]
        while prev[end] != -1:
            path.append(prev[end])
            end = prev[end]
            
        if len(path) % 2 == 1:
            return path[len(path) / 2:len(path) / 2 + 1]
        else:
            return path[len(path) / 2 - 1: len(path) / 2 + 1]
                