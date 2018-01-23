class Solution(object):
    def positiveToHex(self, num):
        l = []
        while num > 0:
            l.append(num % 16)
            num //= 16
        while len(l) < 8:
            l.append(0)
        return l

    # 补码
    def complement(self, l):
        for i in range(len(l)):
            l[i] = 15 - l[i]
        carry = (l[0] + 1) // 16
        l[0] = (l[0] + 1) % 16
        for i in range(1, len(l)):
            sum = l[i] + carry
            carry = sum // 16
            l[i] = sum % 16
        return l

    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        d = {10:'a', 11:'b', 12:'c', 13:'d', 14:'e', 15:'f'}
        for i in range(10):
            d[i] = str(i)
        if num > 0:
            l = self.positiveToHex(num)
        else:
            l = self.complement(self.positiveToHex(-num))
        l.reverse()
        ans = ""
        i = 0
        while i < len(l) and l[i] == 0:
            i += 1
        while i < len(l):
            ans += str(d[l[i]])
            i += 1
        return ans

if __name__ == '__main__':
    sol = Solution()
    print(sol.toHex(-26))
