class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        rewarded = True
        i = 0
        countA = 0
        while i < len(s):
            if s[i] == 'A':
                countA += 1
                if countA > 1:
                    rewarded = False
                    break
            if s[i] == 'L' and i > 1 and s[i-1] == 'L' and s[i-2] == 'L':
                    rewarded = False
                    break
            i += 1
        return rewarded
