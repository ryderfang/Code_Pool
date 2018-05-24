import string

class Solution:
    """ 二维数组行列交换
    """
    @staticmethod
    def zig(grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        return list(zip(*grid))

    """ 生成字母、数字表
    """
    @staticmethod
    def alpha_lower_list():
        return list(string.ascii_lowercase)
    @staticmethod
    def alpha_upper_list():
        return list(string.ascii_uppercase)
    @staticmethod
    def alpha_digit():
        return list(string.ascii_lowercase) + list(map(lambda x: str(x), list(range(0, 10)))) + list(string.ascii_uppercase)

    