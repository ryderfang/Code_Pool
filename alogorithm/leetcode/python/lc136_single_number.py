class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for i in nums:
            res ^= i
        return res

# Testcase
if __name__ == '__main__':
    sol = Solution()
    param = [1, 1, 2, 2, 3]
    print(sol.singleNumber(param))
