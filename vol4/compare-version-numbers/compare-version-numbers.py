class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        num1 = map(int, version1.split('.'))
        num2 = map(int, version2.split('.'))
        for i in range(max(len(num1), len(num2))):
            if i >= len(num1):
                num1 = num1 + [0]
            if i >= len(num2):
                num2 = num2 + [0]
            if num1[i] > num2[i]:
                return 1
            if num1[i] < num2[i]:
                return -1
        return 0