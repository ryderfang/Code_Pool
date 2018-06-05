#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import os


def find(path):
    ret = []
    for parent, _, files in os.walk(path):
        for f in files:
            src = os.path.join(parent, f)
            dst = os.path.join(parent, f.replace('_', '-'))
            os.rename(src, dst)
            ret.append(dst)
            
    print(len(ret))
    return ret

def solutions(path):
    ret = []
    for _, _, files in os.walk(path):
        for f in files:
            ret.append(int(f[0:f.index('-')][2:]))
    ret.sort()
    ret = [str(x).zfill(3) for x in ret]
    print(len(ret))
    return ret

PATH = os.getcwd() + '/algorithm/leetcode/'

if __name__ == "__main__":
    ret = solutions(PATH)
    for i in ret:
        print(i)
