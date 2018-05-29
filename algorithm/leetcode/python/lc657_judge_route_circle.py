class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def moveLeft(self):
        self.x -=1
    def moveRight(self):
        self.x += 1
    def moveUp(self):
        self.y -= 1
    def moveDown(self):
        self.y += 1
    def Equal(self, op):
        if self.x == op.x and self.y == op.y:
            return True
        return False

class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        p = Point(0, 0)
        for ch in moves:
            if ch == 'L':
                p.moveLeft()
            if ch == 'R':
                p.moveRight()
            if ch == 'U':
                p.moveUp()
            if ch == 'D':
                p.moveDown()
        return p.Equal(Point(0, 0))
        