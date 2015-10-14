import string

class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        alphabet = string.uppercase
        ret = ''
        while n > 0:
            ret = alphabet[(n - 1) % 26] + ret
            n = (n - 1) / 26
        return ret
        