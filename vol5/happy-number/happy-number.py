class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        s = set()
        while n not in s:
            s.add(n)
            n = sum(int(x) * int(x) for x in str(n))
            if n == 1:
                return True
        return False