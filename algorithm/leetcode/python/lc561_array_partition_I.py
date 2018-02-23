class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        sum = 0
        for i in range(len(nums)):
            if (i % 2 == 0):
                sum +=  nums[i]
        return sum


# Testcase
if __name__ == '__main__':
    sol = Solution()
    param = [1, 4, 3, 2]
    print(sol.arrayPairSum(param))
