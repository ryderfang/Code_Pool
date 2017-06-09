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

if __name__ == '__main__':
    pass
