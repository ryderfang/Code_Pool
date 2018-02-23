import sys

class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        d = {}
        imax = -sys.maxsize
        imin = sys.maxsize
        for i in nums:
            imax = max(imax, i)
            imin = min(imin, i)
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        ans = 0
        l = d.keys()
        l.sort()
        for i in range(len(l) - 1):
            if l[i+1] - l[i] == 1:
                ans = max(ans, d[l[i]] + d[l[i+1]])
        return ans
