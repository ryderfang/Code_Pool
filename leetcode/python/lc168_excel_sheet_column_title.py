class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        l = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        d = {}
        for i in range(len(l)):
            d[i + 1] = l[i]
        d[0] = 'Z'
        s = []
        while n > 0:
            if n == 26:
                s.append('Z')
                break;
            s.append(d[n % 26])
            if n % 26 == 0:
                n -= 26
            n = n // 26
        s.reverse()
        return "".join(s)
