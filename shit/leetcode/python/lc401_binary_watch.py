class Solution(object):
    # bit 1's count in `n`
    def bitCount(self, n):
        c = 0
        while n:
            n &= (n - 1)
            c += 1
        return c
        
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        dh = {}
        dm = {}
        for n in range(60):
            bc = self.bitCount(n)
            if bc in dm:
                dm[bc].append(n)
            else:
                dm[bc] = [n]
            if n < 12:
                if bc in dh:
                    dh[bc].append(n)
                else:
                    dh[bc] = [n]
        print(dh)
        print(dm)

        if num > 10:
            return []
        ans = []
        for i in range(min(4, num) + 1):
            if (i in dh) and ((num - i) in dm):
                hl = dh[i]
                ml = dm[num-i]
                for j in hl:
                    for k in ml:
                        ans.append('{0}:{1}'.format(str(j), str(k).zfill(2)))
        return ans


if __name__ == '__main__':
    sol = Solution()
    print(sol.readBinaryWatch(1))
