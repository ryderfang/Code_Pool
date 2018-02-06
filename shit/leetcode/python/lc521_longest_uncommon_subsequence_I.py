class Solution(object):
    def findLUSlength(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        if a == b:
            return -1
        return max(len(a), len(b))

# Testcase
if __name__ == '__main__':
    sol = Solution()
    pa = "aaaa"
    pb = "aaab"
    print(sol.findLUSlength(pa, pb))
