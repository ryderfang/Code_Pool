#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution:
    def __init__(self):
        self.ret = []
        self.visited = []
        self.graph = []

    def find(self, node, dst, stack):
        self.visited[node] = 1
        stack.append(node)
        for x in self.graph[node]:
            if x == dst:
                self.ret.append(stack + [dst])
        for x in self.graph[node]:
            if self.visited[x] == 0 and x != dst:
                self.find(x, dst, stack)
        t = stack.pop()
        # 核心在这里，DFS 所有子节点后，当前节点可能还会使用，所以重置 visited
        self.visited[t] = 0

    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        self.ret = []
        self.visited = [0 for _ in range(len(graph))]
        self.graph = graph
        stack = []
        self.find(0, len(graph) - 1, stack)
        return self.ret
        

if __name__ == "__main__":
    sol = Solution()
    print(sol.allPathsSourceTarget([[4,3,1],[3,2,4],[3],[4],[]]))
