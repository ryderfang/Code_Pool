class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        d = {}
        for n in nums:
            if n in d:
                d[n] += 1
            else:
                d[n] = 1
            if d[n] > l // 2:
                return n
