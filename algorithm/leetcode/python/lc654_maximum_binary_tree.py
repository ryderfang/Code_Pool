class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return TreeNode(nums[0])
        t = TreeNode(max(nums))
        idx = nums.index(t.val)
        t.left = self.constructMaximumBinaryTree(nums[0:idx])
        t.right = self.constructMaximumBinaryTree(nums[idx+1:])
        return t

import sys
sys.path.append(sys.path[0] + '/../../')
print(sys.path)
from common import python_tree

if __name__ == '__main__':
    sol = Solution()
    t = sol.constructMaximumBinaryTree([3, 2, 1, 6, 0, 5])
    print(python_tree.level_order_binary_tree(t))
