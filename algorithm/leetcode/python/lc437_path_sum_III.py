# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import copy

class Solution(object):
    ans = 0
    def find(self, node, sum, pl):
        '''
        l = copy.deepcopy(pl)
        <- 深copy超慢!!
        '''
        l = copy.copy(pl)
        if node == None:
            return
        csum = node.val
        if len(l) > 0:
            csum = l[-1] + node.val
        if csum == sum:
            self.ans += 1
        cnt = l.count(csum - sum)
        if cnt > 0:
            self.ans += cnt
        l.append(csum)
        self.find(node.left, sum, l)
        self.find(node.right, sum, l)

    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if root == None:
            return 0
        self.find(root, sum, [])
        return self.ans

import sys
sys.path.append(sys.path[0] + '/../../../')
print(sys.path)
from toys import python_kit

if __name__ == '__main__':
    sol = Solution()
    root = python_kit.list_to_binary_tree([1])
    print(sol.pathSum(root, 0))
