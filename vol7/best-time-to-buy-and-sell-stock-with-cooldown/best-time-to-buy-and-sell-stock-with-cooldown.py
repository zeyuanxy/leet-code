#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-24 02:29:22
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-24 02:29:28
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        n = len(prices)
        buy = [0] * n
        sell = [0] * n
        buy[0] = -prices[0]
        for i in range(1, n):
            buy[i] = max(-prices[i], buy[i - 1], sell[i - 2] - prices[i])
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i])
        return max(sell)