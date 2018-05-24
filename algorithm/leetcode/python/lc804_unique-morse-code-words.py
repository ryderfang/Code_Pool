class Solution:
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        ret = []
        for w in words:
            temp = ""
            for ch in w:
                temp += morse[ord(ch) - ord('a')]
            ret.append(temp)
        ret = set(ret)
        return len(ret)

if __name__ == '__main__':
    sol = Solution()
    sol.uniqueMorseRepresentations(["gin", "zen", "gig", "msg"])