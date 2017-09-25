# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.maxPath = 0

    def depth(self, node, ans = [0]):
        if node == None:
            return
        if node.left != None or node.right != None:
            s = [0]
            self.depth(node.left, s)
            t = [0]
            self.depth(node.right, t)
            ans[0] = max(s[0], t[0])
            self.maxPath = max(self.maxPath, s[0] + t[0])
        ans[0] += 1

    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        self.depth(root)
        return self.maxPath

'''
[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]
'''