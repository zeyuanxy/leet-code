class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """ 
        while n % 4 == 0:
            n /= 4
        if n % 8 == 7:
            return 4
        for a in range(0, n / 2 + 1):
            if a * a > n / 2:
                break
            from math import sqrt
            b = int(sqrt(n - a * a))
            if a * a + b * b == n:
                if a == 0:
                    return 1
                else:
                    return 2
        return 3