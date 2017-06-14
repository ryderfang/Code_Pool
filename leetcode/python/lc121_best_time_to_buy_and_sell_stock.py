import sys

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        ans = 0
        minP = sys.maxsize
        for p in prices:
            ans = max(ans, p - minP)
            minP = min(p, minP)
        return ans
