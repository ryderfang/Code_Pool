class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        for i in range(31):
            if ((1 << i) ^ n) == 0:
                print (i, 1 << i)
                return True
        else:
            return False
