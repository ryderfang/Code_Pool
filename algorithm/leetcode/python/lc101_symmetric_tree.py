# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        left_pre_order = []
        stack = [root]
        while len(stack) > 0:
            top = stack.pop()
            if top != None:
                left_pre_order.append(top.val)
                stack.append(top.right)
                stack.append(top.left)
            else:
                left_pre_order.append(None)
        right_pre_order = []
        stack = [root]
        while len(stack) > 0:
            top = stack.pop()
            if top != None:
                right_pre_order.append(top.val)
                stack.append(top.left)
                stack.append(top.right)
            else:
                right_pre_order.append(None)
        print(left_pre_order, right_pre_order)
        return left_pre_order == right_pre_order
