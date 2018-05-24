class Solution:
    @staticmethod
    def zig(grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        return list(zip(*grid))