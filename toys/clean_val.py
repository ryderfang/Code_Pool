#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import os
import re
import python_kit


def process(line):
    return re.sub(r'g_isIpad\s*\?.*:\s*', '', line)


def find_and_replace(filename):
    if not (os.path.isfile(filename) and os.path.splitext(filename)[1] == ".m"):
        print(os.path.splitext(filename)[1])
        print('Not objc file!')
        return False

    with open(filename, 'r', encoding='utf-8') as f:
        contents = f.readlines()
    with open(filename, 'w+', encoding='utf-8') as f:
        #print(contents)
        #print('==================')
        f.seek(0)
        begin_if = False
        end_if = False
        begin_else = False
        end_else = False
        for line in contents:
            new_line = process(line)
            if end_if:
                begin_if = False
                end_if = False
            if end_else:
                begin_else = False
                end_else = False
            if re.match(r'^\s*if\s*\(g_isIpad\)\s*{\s*$', new_line):
                begin_if = True
            if begin_if:
                if re.match(r'^\s*}\s*$', new_line):
                    end_if = True
                if re.match(r'^\s*}\s*else\s*\{\s*$', new_line):
                    end_if = True
                    begin_else = True
            if begin_else and re.match(r'^\s*}\s*$', new_line):
                end_else = True
            if not begin_if and not end_else:
                f.write(new_line)
        # m = re.match(r'.*if\s*\(g_isIpad\)\s*\{(?P<ifp>.*)\}.*else\s*\{(?P<elsep>.*)\}.*', content, re.S)
        # if m is not None:
        #     #print(m.groups())
        #     content = re.sub(r'if\s*\(g_isIpad\)\s*\{(?P<ifp>.*)\}.*else\s*\{(?P<elsep>.*)\}', m.groups()[1],
        #                      content, flags=re.S)
        #     print(content)


def main():
    if len(sys.argv) < 2:
        print("No file!")
    else:
        param = sys.argv[1]
        if os.path.isfile(param):
            #find_and_replace(param)
            arr = python_kit.get_array_from_file(param)
            for ln in arr:
                print(ln)
                find_and_replace(ln)
        elif os.path.isdir(param):
            objc_files = python_kit.retrieve_path(param)
            with open('/Users/fangr/Coding/Code_Pool/phonebase.txt', 'w') as f:
                for name in objc_files:
                    f.write(name + '\r\n')


if __name__ == '__main__':
    main()
