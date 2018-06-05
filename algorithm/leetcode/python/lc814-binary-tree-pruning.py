# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pruneTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root == None:
            return None
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        if root.left == None and root.right == None and root.val == 0:
            return None
        return root
    
import sys
sys.path.append(sys.path[0] + '/../../')
print(sys.path)
from common import python_tree

if __name__ == '__main__':
    sol = Solution()
    t = sol.pruneTree(python_tree.list_to_binary_tree([1,1,0,1,1,0,1,0]))
    print(python_tree.level_order_binary_tree(t))
