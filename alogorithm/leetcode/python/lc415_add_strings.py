class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        sumLenth = max(len(num1), len(num2))
        # 左补0
        l1 = list(num1.zfill(sumLenth))
        l2 = list(num2.zfill(sumLenth))
        l1.reverse()
        l2.reverse()
        print(l1, l2)
        carry = 0
        s = []
        for i in range(sumLenth):
            t = int(l1[i]) + int(l2[i]) + carry
            s.append(str(t % 10))
            carry = t / 10
        s.append(str(carry))
        s.reverse()
        i = 0
        while i < len(s) - 1 and s[i] == '0':
            i += 1
        s = s[i:]
        return "".join(s)
