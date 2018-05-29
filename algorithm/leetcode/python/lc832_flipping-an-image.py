#! /usr/bin/env python
# -*- coding: utf-8 -*-

import math

class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for i in range(0, len(A)):
            t = A[i]
            t.reverse()
            t = list(map(lambda x:1-x, t))
            A[i] = t
        return A


if __name__ == "__main__":
    sol = Solution()
    print(sol.flipAndInvertImage([[1,1,0],[1,0,1],[0,0,0]]))
