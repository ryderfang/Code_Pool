import sys

class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = sum(nums)
        isEqual = True
        for x in nums:
            if x != nums[0]:
                isEqual = False
                break;
        if isEqual:
            return 0
        l = len(nums)
        maxn = max(nums)
        minn = min(nums)
        """
        (x * l - s) % (l - 1) == 0
        x >= maxn
        x - minn <= (x * l - s) / (l - 1) = y = ans
        => y >= maxn - minn
        => y >= s - minn * l
        l * x - (l - 1) * y = s 整数点
        """
        ans = max(maxn - minn, s - minn * l)
        while (s + (l - 1) * ans) % l != 0:
            ans += 1
        return ans

# Testcase
if __name__ == '__main__':
    sol = Solution()
    param = [-100, 0, 100]
    print(sol.minMoves(param))