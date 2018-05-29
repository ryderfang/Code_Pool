# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, s, t):
        if (s == None) == (t == None):
            if s != None and t != None:
                return s.val == t.val and \
                    self.isSameTree(s.left, t.left) and \
                    self.isSameTree(s.right, t.right)
            else:
                return True
        else:
            return False
        
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        isSame = False
        stack = [s]
        while len(stack):
            top = stack.pop()
            if self.isSameTree(top, t):
                isSame = True
                break
            if top != None:
                stack.append(top.right)
                stack.append(top.left)
        return isSame

import sys
sys.path.append(sys.path[0] + '/../../../')
print(sys.path)
from toys import python_kit

if __name__ == '__main__':
    sol = Solution()
    root = python_kit.list_to_binary_tree([3,4,5,1,2])
    node = python_kit.list_to_binary_tree([4,1,2])
    print(sol.isSubtree(root, node))
