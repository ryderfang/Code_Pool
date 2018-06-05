#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        cnt = 0
        line = 0
        for ch in S:
            line += widths[ord(ch) - ord('a')]
            if line >= 100:
                cnt += 1
                if line == 100:
                    line = 0
                else:
                    line = widths[ord(ch) - ord('a')]
        if line > 0:
            cnt += 1
        return [cnt, line]
        

if __name__ == "__main__":
    sol = Solution()
    print(sol.numberOfLines([4,10,10,99,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,90,10,10,10], "abcdefghijklmnopqrstuvwxyz"))
