class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        ans = (D - B) * (C - A) + (H - F) * (G - E)
        h = min(C, G) - max(A, E)
        v = min(D, H) - max(B, F)
        if h <= 0 or v <= 0:
            return ans
        ans -= h * v
        return ans