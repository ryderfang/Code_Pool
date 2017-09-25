class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        if len(ransomNote) > len(magazine):
            return False
        lr = list(ransomNote)
        lm = list(magazine)
        lr.sort()
        lm.sort()
        lenr = len(lr)
        lenm = len(lm)
        i = 0
        j = 0
        while i < lenr and j < lenm:
            if lr[i] == lm[j]:
                i += 1
                j += 1
            else:
                j += 1
        return (i == lenr)
