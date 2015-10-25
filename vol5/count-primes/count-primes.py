class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        isPrime = [True] * n
        ans = 0
        for i in xrange(2, n):
            if isPrime[i] == True:
                ans += 1
                for j in xrange(2 * i, n, i):
                    isPrime[j] = False
        return ans