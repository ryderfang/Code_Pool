#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import string

class Solution:
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        count = [0 for _ in range(26)]
        for ch in T:
            count[ord(ch) - ord('a')] += 1
        ret = ''
        for ch in S:
            ret += ch * count[ord(ch) - ord('a')]
        rest = set(T) - set(S)
        for ch in rest:
            ret += ch * count[ord(ch) - ord('a')]
        return ret


if __name__ == "__main__":
    sol = Solution()
    print(sol.customSortString('cbdfe', 'kkooaaaabbbcccdddffeegggg'))
