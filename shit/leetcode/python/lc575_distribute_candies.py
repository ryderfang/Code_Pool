class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        count = len(candies) / 2
        dic = {}
        for i in candies:
            dic[i] = 1
        kinds = len(dic)
        return int(min(count, kinds))

# Testcase
if __name__ == '__main__':
    sol = Solution()
    param = [1, 1, 2, 2]
    print(sol.distributeCandies(param))
