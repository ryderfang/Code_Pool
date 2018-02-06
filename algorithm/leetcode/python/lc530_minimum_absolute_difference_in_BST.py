# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# BST: self.left < self.value < self.right

import sys

class Solution(object):
    def __getNode(self, nums, root):
        if root == None:
            return
        self.__getNode(nums, root.left)
        nums.append(root.val)
        self.__getNode(nums, root.right)

    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        nums = []
        self.__getNode(nums, root)
        ans = sys.maxsize
        i = 0
        while i < len(nums) - 1:
            ans = min(ans, nums[i+1] - nums[i])
            i += 1
        return ans
