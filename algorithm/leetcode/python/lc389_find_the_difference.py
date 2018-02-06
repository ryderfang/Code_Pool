class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        ss = sorted(s)
        st = sorted(t)
        for i in range(len(ss)):
            if st[i] != ss[i]:
                return st[i]
        return st[-1]

# Testcase
if __name__ == '__main__':
    sol = Solution()
    pa = "abcd"
    pb = "abcde"
    print(sol.findTheDifference(pa, pb))
