#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        count = 0
        for i in range(len(board)):
            j = 0
            while j < len(board[0]):
                if i > 0 and board[i-1][j] == 'X':
                    j += 1
                elif board[i][j] == 'X':
                    count += 1
                    while j < len(board[0]) and board[i][j] == 'X':
                        j += 1
                else:
                    j += 1
        return count

if __name__ == "__main__":
    sol = Solution()
    print(sol.countBattleships(['X..X', '....', '...X']))
