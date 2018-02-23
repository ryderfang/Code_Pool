class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        d = {}
        for i in range(len(l)):
            d[l[i]] = i + 1
        ls = list(s)
        ls.reverse()
        fact = 1
        ans = 0
        for ch in ls:
            ans += d[ch] * fact
            fact *= 26
        return ans
