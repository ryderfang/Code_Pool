#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        mp = [0 for _ in range(len(rooms))]
        stack = [0]
        while len(stack) > 0:
            t = stack.pop()
            mp[t] = 1
            for x in rooms[t]:
                if mp[x] == 0:
                    stack.append(x)
        return (mp.count(0) == 0)
            

if __name__ == "__main__":
    sol = Solution()
    print(sol.canVisitAllRooms([[1,3],[3,0,2],[2],[0]]))