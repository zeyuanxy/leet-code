class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        L = 10
        if len(s) <= L:
            return []
        
        counter = {}
        m = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        value = 0
        for i in range(L):
            value = 4 * value + m[s[i]]
        counter[value] = 1
        
        ret = []
        for i in range(L, len(s)):
            value = (value - pow(4, L - 1) * m[s[i - L]]) * 4 + m[s[i]]
            counter[value] = counter.get(value, 0) + 1
            if counter[value] == 2:
                ret.append(s[i - 9:i + 1])
                    
        return ret
            
        