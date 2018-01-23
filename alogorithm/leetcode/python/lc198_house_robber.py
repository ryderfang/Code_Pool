class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        elif len(nums) <= 2:
            return max(nums)
        # f[x] -> num[x]结尾的最大值
        f = [nums[0], nums[1]]
        for i in range(2, len(nums)):
            c = max(f[:-1]) + nums[i]
            f.append(c)
        return max(f)
        
if __name__ == '__main__':
    sol = Solution()
    print(sol.rob([1,2,3,4,1,1,6]))
