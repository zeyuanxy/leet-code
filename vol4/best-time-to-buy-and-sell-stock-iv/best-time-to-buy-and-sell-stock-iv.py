#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-06 21:51:30
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-06 21:51:36
class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if k > n / 2:
            ans = 0
            for i in range(1, n):
                ans += max(prices[i] - prices[i - 1], 0)
            return ans
        dp = [None] * (2 * k + 1)
        dp[0] = 0
        for i in range(n):
            for j in range(min(2 * k, i + 1), 0, -1):
                if j % 2 == 0:
                    dp[j] = max(dp[j], dp[j - 1] + prices[i])
                else:
                    dp[j] = max(dp[j], dp[j - 1] - prices[i])
        return max(dp)