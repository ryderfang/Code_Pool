class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        idx = 0
        while idx < len(nums) - 1:
            if nums[idx] == 0:
                idx_not_zero = idx + 1
                while idx_not_zero < len(nums) and nums[idx_not_zero] == 0:
                    idx_not_zero += 1
                if idx_not_zero < len(nums) and nums[idx_not_zero] != 0:
                    t = nums[idx]
                    nums[idx] = nums[idx_not_zero]
                    nums[idx_not_zero] = t
            idx += 1

# Testcase
if __name__ == '__main__':
    sol = Solution()
    param = [0,1,0,3,12]
    print(sol.moveZeroes(param))
