#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys


def comp(a, b):
    print(a, b)
    if len(a) != len(b):
        return 1 if len(a) > len(b) else -1
    i = 0
    while i < len(a):
        if a[i] != b[i]:
            return 1 if a[i] > b[i] else -1
        i += 1
    return 0

if __name__ == '__main__':
    print(comp(sys.argv[1], sys.argv[2]))
