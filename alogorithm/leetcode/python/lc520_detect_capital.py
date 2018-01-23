class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if word.capitalize() == word or \
           word.upper() == word or      \
           word.lower() == word:
           return True
        return False
