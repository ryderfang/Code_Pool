# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findPath(self, tree, node, l):
        l.append(tree)
        if tree.val > node.val:
            self.findPath(tree.left, node, l)
        elif tree.val < node.val:
            self.findPath(tree.right, node, l)

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        l1 = []
        l2 = []
        self.findPath(root, p, l1)
        self.findPath(root, q, l2)
        i = 0
        while i < len(l1) and i < len(l2):
            if l1[i] != l2[i]:
                break
            i += 1
        return l1[i-1]

import sys
sys.path.append(sys.path[0] + '/../../')
print(sys.path)
from toys import python_kit

if __name__ == '__main__':
    sol = Solution()
    root = python_kit.list_to_binary_tree([6, 2, 8, 0, 4, 7, 9, None, None, 3, 5])
    print(sol.lowestCommonAncestor(root, root.left, root.right))

