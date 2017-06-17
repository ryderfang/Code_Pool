# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        stack = [(root, 0)]
        d = {}
        while len(stack) > 0:
            top = stack.pop()
            node = top[0]
            height = top[1]
            if node != None:
                if height in d:
                    d[height].append(node.val)
                else:
                    d[height] = [node.val]
                stack.append((node.right, height + 1))
                stack.append((node.left, height + 1))
        treeHeight = max(d.keys())
        ans = []
        for i in range(treeHeight, -1, -1):
            ans.append(d[i])
        return ans
