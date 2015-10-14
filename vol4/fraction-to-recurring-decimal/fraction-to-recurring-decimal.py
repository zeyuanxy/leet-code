import fractions

class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator % denominator == 0:
            return str(numerator / denominator)
    
        ret = ''
        if numerator * denominator < 0:
            ret = '-'
        numerator = abs(numerator)
        denominator = abs(denominator)
        ret += str(numerator / denominator) + '.'
        numerator %= denominator
        
        m = {}
        while numerator != 0:
            if numerator in m:
                ret = ret[:m[numerator]] + '(' + ret[m[numerator]:] + ')'
                return ret
            else:
                m[numerator] = len(ret)
            numerator *= 10
            ret += str(numerator / denominator)
            numerator %= denominator
        
        return ret