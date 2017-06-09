class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        d = {}
        for n in nums:
            if n in d:
                return True
            else:
                d[n] = 1
        else:
            return False
