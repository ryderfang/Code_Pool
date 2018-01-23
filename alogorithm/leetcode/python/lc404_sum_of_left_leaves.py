# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        stack = []
        stack.append(root)
        left = []
        while len(stack) > 0:
            node = stack.pop()
            if node != None:
                stack.append(node.left)
                if node.left != None and \
                   node.left.left == None and \
                   node.left.right == None:
                    left.append(node.left.val)
                stack.append(node.right)
        return sum(left)
