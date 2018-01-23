import sys

class Solution(object):
    # O(n)
    def _maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = -sys.maxsize
        i = j = 0
        s = e = 0
        temp = 0
        while j < len(nums):
            temp += nums[j]
            if temp > ans:
                ans = temp
                s = i
                e = j
            if temp < 0:
                i = j + 1
                temp = 0
            j += 1
        return ans

    # O(nlogn)
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 1:
            return nums[0]
        mid = length // 2
        left = nums[:mid]
        right = nums[mid:]
        maxLeft = self.maxSubArray(left)
        maxRight = self.maxSubArray(right)
        left.reverse()
        sl = -sys.maxsize
        temp = 0
        for i in range(mid):
            temp += left[i]
            sl = max(temp, sl)
        sr = -sys.maxsize
        temp = 0
        for i in range(length - mid):
            temp += right[i]
            sr = max(temp, sr)
        return max(sl + sr, max(maxLeft, maxRight))
        