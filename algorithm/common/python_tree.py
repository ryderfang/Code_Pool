#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# List 转换成 Tree
def list_to_binary_tree(l):
    if len(l) == 0 or l[0] == None:
        return None
    queue = []
    root = TreeNode(l[0])
    queue.append(root)
    i = 1
    while len(queue) > 0 and i < len(l):
        print(queue)
        left = None
        if i < len(l) and l[i] != None:
            left = TreeNode(l[i])
        i += 1
        right = None
        if i < len(l) and l[i] != None:
            right = TreeNode(l[i])
        i += 1
        queue[0].left = left
        queue[0].right = right
        queue = queue[1:]
        if left != None:
            queue.append(left)
        if right != None:
            queue.append(right)
    return root

# 前序 - 根左右
def pre_order_binary_tree(root):
    ans = []
    stack = [root]
    while len(stack) > 0:
        top = stack.pop()
        if top != None:
            ans.append(top.val)
            stack.append(top.right)
            stack.append(top.left)
    return ans

# 中序 - 左根右
def mid_order_binary_tree(root):
    ans = []
    stack = []
    p = root
    while p != None or len(stack) > 0:
        while p != None:
            stack.append(p)
            p = p.left
        if len(stack) > 0:
            p = stack.pop()
            ans.append(p.val)
            p = p.right
    return ans

# 后序 - 左右根
def post_order_binary_tree(root):
    ans = []
    stack = []
    stack.append((root, False))
    while len(stack) > 0:
        top = stack.pop()
        p = top[0]
        visited = top[1]
        if p == None:
            continue
        if visited:
            ans.append(p.val)
        else:
            stack.append((p, True))
            stack.append((p.right, False))
            stack.append((p.left, False))
    return ans

# 层次遍历
def level_order_binary_tree(root, show_none=True):
    ans = []
    queue = [root]
    cur = 0
    end = 1
    while cur < len(queue):
        end = len(queue)
        while cur < end:
            node = queue[cur]
            if node != None:
                ans.append(node.val)
            elif show_none:
                ans.append(None)

            if node != None:
                if node.left != None:
                    queue.append(node.left)
                elif show_none:
                    queue.append(None)
                if node.right != None:
                    queue.append(node.right)
                elif show_none:
                    queue.append(None)

                # 左右子树都是空，不添加
                if node.left == None and node.right == None:
                    queue.pop()
                    queue.pop()
            cur += 1
    return ans

def tree_height(root):
    if root == None:
        return 0
    return 1 + max(tree_height(root.left), tree_height(root.right))

if __name__ == "__main__":
    root = list_to_binary_tree([1,2,None,3,4,5,None,6])
    ans = level_order_binary_tree(root)