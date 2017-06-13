#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import fileinput


def get_array_from_file(filename):
    out = []
    if not os.path.isfile(filename):
        print(filename + 'is not a file!')
        return out
    with fileinput.input(filename) as f:
        for line in f:
            out.append(line[:-1])
    return out


def retrieve_path(path):
    out = []
    if not os.path.isdir(path):
        print(path + 'is not a path!')
        return out
    for parent, dirs, files in os.walk(path):
        # for d in dirs:
        #     pass
        for f in files:
            if os.path.splitext(f)[1] == '.m':
                out.append(os.path.join(parent, f))
    return out


def comp_big_int(a, b):
    print(a, b)
    if len(a) != len(b):
        return 1 if len(a) > len(b) else -1
    i = 0
    while i < len(a):
        if a[i] != b[i]:
            return 1 if a[i] > b[i] else -1
        i += 1
    return 0

# 补码 twos_complement(0xffffffff, 32) => -1
def twos_complement(input_value, num_bits):
    '''Calculates a two's complement integer from the given input value's bits'''
    mask = 2**(num_bits - 1)
    return -(input_value & mask) + (input_value & ~mask)

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
# list to binary tree
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
        if i < len(l):
            left = TreeNode(l[i])
        i += 1
        right = None
        if i < len(l):
            right = TreeNode(l[i])
        i += 1
        queue[0].left = left
        queue[0].right = right
        queue = queue[1:]
        queue.append(left)
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

def tree_height(root):
    if root == None:
        return 0
    return 1 + max(tree_height(root.left), tree_height(root.right))


if __name__ == '__main__':
    pass
