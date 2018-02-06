class Solution(object):
    # 补码
    def negative(self, x):
        return self.getSum(~x, 1)

    def sub(self, a, b):
        return self.getSum(a, self.negative(b))

    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        if a == 0:
            return b
        if b == 0:
            return a
        if a < 0 and b > 0:
            pa = self.negative(a)
            if b > pa:
                pb = self.negative(b)
                return self.negative(self.getSum(pa, pb))
            elif b == pa:
                return 0
        if a > 0 and b < 0:
            pb = self.negative(b)
            if a > pb:
                pa = self.negative(a)
                return self.negative(self.getSum(pa, pb))
            elif a == pb:
                return 0
        ans = 0
        while b:
            ans = a ^ b
            b = (a & b) << 1
            print(ans, b)
            a = ans
        return ans

# Testcase
if __name__ == '__main__':
    sol = Solution()
    pa = -12
    pb = 11 
    print(sol.getSum(pa, pb))
