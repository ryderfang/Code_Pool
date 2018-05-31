#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def nums(self, n):
        return list(map(lambda c: int(c), str(n)))

    def check(self, n):
        l = self.nums(n)
        if l.count(0) > 0:
            return False
        ret = True
        for i in l:
            if n % i != 0:
                ret = False
                break
        return ret
    
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        ret = []
        for i in range(left, right + 1):
            if self.check(i):
                ret.append(i)
        return ret


if __name__ == "__main__":
    sol = Solution()
    print(sol.selfDividingNumbers(1, 22))
