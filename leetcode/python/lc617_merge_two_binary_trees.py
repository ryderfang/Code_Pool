# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        t = TreeNode(0)
        if t1 == None and t2 == None:
            return None
        if t1 != None and t2 != None:
            t.val = t1.val + t2.val
            t.left = self.mergeTrees(t1.left, t2.left)
            t.right = self.mergeTrees(t1.right, t2.right)
        if t1 == None and t2 != None:
            t.val = t2.val
            t.left = self.mergeTrees(None, t2.left)
            t.right = self.mergeTrees(None, t2.right)
        if t1 != None and t2 == None:
            t.val = t1.val
            t.left = self.mergeTrees(t1.left, None)
            t.right = self.mergeTrees(t1.right, None)
        return t
