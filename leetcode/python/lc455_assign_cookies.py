class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()
        g_idx = 0
        s_idx = 0
        ans = 0
        while g_idx < len(g) and s_idx < len(s):
            if g[g_idx] <= s[s_idx]:
                ans += 1
                g_idx += 1
            s_idx += 1
        return ans
