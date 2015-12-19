#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-12-19 22:10:41
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-12-19 22:10:47
import math

class Solution(object):
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int(math.sqrt(n))