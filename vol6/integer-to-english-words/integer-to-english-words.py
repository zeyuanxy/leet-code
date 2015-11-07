#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-06 21:35:56
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-06 21:36:07
class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return 'Zero'
        less20 = ['One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 
               'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
        tens = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
        
        def words(num):
            if num == 0:
                return []
            elif num < 20:
                return [less20[num - 1]]
            elif num < 100:
                return [tens[num / 10 - 2]] + words(num % 10)
            elif num < 1000:
                return [less20[num / 100 - 1], 'Hundred'] + words(num % 100)
            elif num < 10 ** 6:
                return words(num / (10 ** 3)) + ['Thousand'] + words(num % (10 ** 3))
            elif num < 10 ** 9:
                return words(num / (10 ** 6)) + ['Million'] + words(num % (10 ** 6))
            else:
                return words(num / (10 ** 9)) + ['Billion'] + words(num % (10 ** 9))
        
        return ' '.join(words(num))