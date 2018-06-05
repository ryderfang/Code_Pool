class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "0"
        t = num
        l = []
        isNegative = (t < 0)
        t = abs(t)
        while t != 0:
            l.append(str(t % 7))
            t //= 7
        if isNegative:
            l.append('-')
        l.reverse()
        return "".join(l)
