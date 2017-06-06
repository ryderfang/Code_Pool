import sys

class Solution(object):
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        if len(ops) == 0:
            return m * n
        r = ops[0][0]
        c = ops[0][1]
        for op in ops:
            r = min(r, op[0])
            c = min(c, op[1])
        return r * c
