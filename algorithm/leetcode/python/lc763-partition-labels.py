#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def lastIndex(self, S, v):
        if S.count(v) == 0:
            return -1
        idx = S.index(v)
        if S.count(v) == 1:
            return idx
        return idx + 1 + self.lastIndex(S[idx + 1:], v)
    
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        idx = 0
        ret = []
        start = 0
        while idx < len(S):
            end = self.lastIndex(S, S[start])
            while idx + 1 <= end:
                idx += 1
                t = self.lastIndex(S, S[idx])
                if t > end:
                    end = t
            idx += 1
            ret.append(idx - start)
            print(S[start:idx])
            start = idx
        return ret




if __name__ == "__main__":
    sol = Solution()
    print(sol.partitionLabels('ababcbacadefegdehijhklijof'))
    # print(sol.lastIndex('ababcbacadefegdehijhklij', 'i'))
