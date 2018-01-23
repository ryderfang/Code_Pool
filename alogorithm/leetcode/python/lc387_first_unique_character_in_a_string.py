class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        for ch in s:
            if ch in d:
                d[ch] = -1
            else:
                d[ch] = 1
        print(d)
        for ch in s:
            if d[ch] > 0:
                return s.index(ch)
        else:
            return -1
