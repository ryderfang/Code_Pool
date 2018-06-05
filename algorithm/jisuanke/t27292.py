#! /usr/bin/env python
# -*- coding: utf-8 -*-

import math

class Solution:
    def solve(self):
        t = int(input())
        for _ in range(0, t):
            n = int(input())
            max_sum = (1 + 2) * (1 + 2) * (n + 1)

            mid = int(math.floor(math.pow(n, 1 / 3)))
            ix = mid
            iy = mid
            iz = n
            min_sum = max_sum
            i = ix
            j = iy
            print(mid)
            while i > 0:
                j = i
                while j < n:
                    t = i * j 
                    if n % t == 0:
                        k = int(n / t)
                        l = [i, j, k]
                        l.sort(reverse=True)
                        temp_sum = (l[0] + 2) * (l[1] + 2) * (l[2] + 1)
                        if temp_sum < min_sum:
                            ix = i
                            iy = j
                            iz = k
                            min_sum = temp_sum
                        #print(ix, iy, iz, temp_sum)
                    j += 1
                i -= 1
            print(ix, iy, iz)
            print(min_sum - n, max_sum - n)
            
if __name__ == "__main__":
    sol = Solution()
    sol.solve()
