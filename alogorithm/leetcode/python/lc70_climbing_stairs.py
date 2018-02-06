import math

# 考虑下大整数
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        for i in range(n // 2 + 1):
            count1 = n - 2 * i
            ans += math.factorial(i + count1) / (math.factorial(i) * math.factorial(count1))
        return ans
