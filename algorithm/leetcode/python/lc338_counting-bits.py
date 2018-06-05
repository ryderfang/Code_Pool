#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def countOf_1(self, num):
        ret = 0
        while num > 0:
            num &= (num -1)
            ret += 1
        return ret
    
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        ret = []
        for i in range(0, num + 1):
            ret.append(self.countOf_1(i))
        return ret

    # best solution
    def _countBits(self, num):
        ret = [0]
        while len(ret) < num + 1:
            ret += [1 + x for x in ret]
        return ret
        

if __name__ == "__main__":
    sol = Solution()
    print(sol.countBits(20))
