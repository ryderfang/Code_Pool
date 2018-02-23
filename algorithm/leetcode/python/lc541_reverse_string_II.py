class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        i = 0
        ans = ""
        while i < len(s):
            t = s[i:i+k]
            ans += t[::-1]
            ans += s[i+k:i+2*k]
            i = i + 2 * k
        return ans
