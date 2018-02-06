class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split(" ")
        result = ""
        isFirst = True
        for w in words:
            chars = list(w)
            chars.reverse()
            if not isFirst:
                result += " "
            result += ("".join(chars))
            isFirst = False
        return result


# Testcase
if __name__ == '__main__':
    sol = Solution()
    param = "Let's take LeetCode contest"
    print(sol.reverseWords(param))
