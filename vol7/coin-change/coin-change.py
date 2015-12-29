#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-12-29 18:41:13
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-12-29 18:41:24
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [amount + 2] * (amount + 1)
        dp[0] = 0
        for coin in coins:
            for value in xrange(amount + 1 - coin):
                if value + coin <= amount:
                    dp[value + coin] = min(dp[value + coin], dp[value] + 1)
        if dp[amount] == amount + 2:
            return -1
        else:
            return dp[amount]