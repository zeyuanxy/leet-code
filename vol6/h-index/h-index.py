class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        if n == 0:
            return 0
        counter = {}
        for i in range(n + 1):
            counter[i] = 0
        for citation in citations:
            if citation > n:
                citation = n
            counter[citation] += 1
        cnt = 0
        ans = 0
        for key in range(n, -1, -1):
            cnt += counter[key]
            ans = max(ans, min(cnt, key))
        return ans