class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        ls = list(s)
        lt = list(t)
        ls.sort()
        lt.sort()
        return ls == lt
