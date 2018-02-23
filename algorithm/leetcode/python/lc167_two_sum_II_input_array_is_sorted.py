class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        i = 0
        while i < len(numbers):
            sub = numbers[i + 1:]
            if sub.count(target - numbers[i]) > 0:
                return [i + 1, sub.index(target - numbers[i]) + i + 2]
            else:
                i = i + numbers.count(numbers[i])
