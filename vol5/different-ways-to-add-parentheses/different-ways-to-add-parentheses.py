class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        ret = []
        for i in xrange(len(input)):
            if input[i] in ['+', '-', '*']:
                l_v = self.diffWaysToCompute(input[:i])
                r_v = self.diffWaysToCompute(input[i + 1:])
                for l in l_v:
                    for r in r_v:
                        v = l + r if input[i] == '+' else l - r if input[i] == '-' else l * r
                        ret.append(v)
        if not ret:
            ret = [int(input)]
        return ret