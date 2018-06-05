#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        mp = {}
        for domain in cpdomains:
            pair = domain.split(' ')
            count = int(pair[0])
            subdomains = pair[1].split('.')
            subdomains.reverse()
            t = ''
            for i in range(len(subdomains)):
                t = subdomains[i] + t
                if t in mp:
                    mp[t] += count
                else:
                    mp[t] = count
                t = '.' + t
        ret = []
        for k, v in mp.items():
            ret.append(str(v) + ' ' + k)
        return ret
        

if __name__ == "__main__":
    sol = Solution()
    print(sol.subdomainVisits(["9001 discuss.leetcode.com"]))
