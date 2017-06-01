class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        ori_row = len(nums)
        ori_col = len(nums[0])
        single_row_list = []
        for row in nums:
            single_row_list.extend(row)
        if ori_row * ori_col == r * c:
            result_list = []
            x = 0
            for i in range(r):
                result_list.append(single_row_list[x : x + c])
                x += c
            return result_list
        else:
            return nums

# Testcase
if __name__ == '__main__':
    sol = Solution()
    param = [[1, 2, 3], [3, 4, 5]]
    print(sol.matrixReshape(param, 3, 2))
