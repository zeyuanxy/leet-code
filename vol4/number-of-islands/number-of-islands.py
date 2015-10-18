class Solution(object):
    def search(self, grid, x, y, s):
        if grid[x][y] == '0' or (x, y) in s:
            return s
        s.add((x, y))
        if x - 1 >= 0:
            s = self.search(grid, x - 1, y, s)
        if x + 1 < len(grid):
            s = self.search(grid, x + 1, y, s)
        if y - 1 >= 0:
            s = self.search(grid, x, y - 1, s)
        if y + 1 < len(grid[0]):
            s = self.search(grid, x, y + 1, s)
        return s
        
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        ans = 0
        s = set()
        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y] == '1' and (x, y) not in s:
                    ans += 1
                    s = self.search(grid, x, y, s)
        return ans