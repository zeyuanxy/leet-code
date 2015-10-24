class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s2t = {}
        t2s = {}
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            if s[i] in s2t:
                token = s2t[s[i]]
                if token != t[i]:
                    return False
                if t2s.get(token, '') != s[i]:
                    return False
            else:
                if t[i] in t2s:
                    return False
                t2s[t[i]] = s[i]
                s2t[s[i]] = t[i]
        return True