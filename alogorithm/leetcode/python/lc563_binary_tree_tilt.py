# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import math

class Solution(object):
    def sumOfSubTree(self, node, sum = [0]):
        if node == None:
            return
        sum[0] += node.val
        self.sumOfSubTree(node.left, sum)
        self.sumOfSubTree(node.right, sum)
        
    def nodeTile(self, node):
        if node == None:
            return 0
        if node.left == None and node.right == None:
            return 0
        leftSum = [0]
        rightSum = [0]
        self.sumOfSubTree(node.left, leftSum)
        self.sumOfSubTree(node.right, rightSum)
        return int(math.fabs(rightSum[0] - leftSum[0]))

    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        ans = 0
        stack = []
        stack.append(root)
        while len(stack) > 0:
            node = stack.pop()
            if node != None:
                ans += self.nodeTile(node)
                stack.append(node.right)
                stack.append(node.left)
        return ans

# Testcase
if __name__ == '__main__':
    sol = Solution()
    param = TreeNode(1)
    param.left = TreeNode(2)
    param.right = TreeNode(3)
    print(sol.findTilt(param))
