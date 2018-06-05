class Solution:
    @staticmethod
    def zig(grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        return list(zip(*grid))

    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = []
        for ln in grid:
            row.append(max(ln))
        col_grid = Solution.zig(grid)
        col = []
        for ln in col_grid:
            col.append(max(ln))
        
        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                ret += (min(row[i], col[j]) - grid[i][j])
        return ret

sol = Solution()
sol.maxIncreaseKeepingSkyline([[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]])
