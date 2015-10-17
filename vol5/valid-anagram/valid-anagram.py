class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        h1 = {}
        h2 = {}
        for c in s:
            h1[c] = h1.get(c, 0) + 1
        for c in t:
            h2[c] = h2.get(c, 0) + 1
        return h1 == h2