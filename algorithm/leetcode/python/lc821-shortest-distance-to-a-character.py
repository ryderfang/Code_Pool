#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        ret = [len(S) for _ in S]
        i = 0
        while i < len(S):
            idx = S.find(C, i)
            if idx != -1:
                for j in range(i, idx):
                    ret[j] = min(ret[j], idx - j)
                for j in range(idx + 1, len(S)):
                    ret[j] = min(ret[j], j - idx)
                ret[idx] = 0
                i = idx + 1
            else:
                for j in range(i, len(S)):
                    ret[j] = j - i + 1
                i = len(S)
        return ret


if __name__ == "__main__":
    sol = Solution()
    print(sol.shortestToChar("loveleetcode", "e"))

