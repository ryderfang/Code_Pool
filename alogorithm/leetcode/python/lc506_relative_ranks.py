class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        sorted_nums = sorted(nums, reverse=True)
        ans = []
        for n in nums:
            idx = sorted_nums.index(n)
            if idx == 0:
                ans.append('Gold Medal')
            elif idx == 1:
                ans.append('Silver Medal')
            elif idx == 2:
                ans.append('Bronze Medal')
            else:
                ans.append(str(idx + 1))
        return ans
