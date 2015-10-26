class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        if n == 0:
            return 0
        l, r = 0, n - 1
        while l < r:
            mid = (l + r) / 2
            if citations[mid] >= n - mid:
                r = mid
            else:
                l = mid + 1
        if citations[l] >= n - l:
            return n - l
        return 0