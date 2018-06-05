class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        for ch in s:
            if ch in d:
                d[ch] += 1
            else:
                d[ch] = 1
        print(d)
        hasExtra = False
        ans = 0
        for ch in d.keys():
            if d[ch] & 1:
                hasExtra = True
            ans += (d[ch] // 2) * 2
        if hasExtra:
            ans += 1
        return ans
