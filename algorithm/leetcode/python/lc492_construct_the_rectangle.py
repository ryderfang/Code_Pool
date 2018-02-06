class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        sqrt = int(area**0.5)
        if sqrt * sqrt == area:
            return [sqrt, sqrt]
        while sqrt * (area // sqrt) != area:
            sqrt -= 1
        return [area // sqrt, sqrt]
