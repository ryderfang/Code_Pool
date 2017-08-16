#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import os
import python_kit

def has_event(str):
    s_arr = ['BiliReportManager', 'BBPhoneAppInfoReport']
    for s in s_arr:
        if str.find(s) >= 0:
            return s
    return ''

def find_and_output(filename):
    result = ''
    last = ''
    last_lno = -1
    has_find = False
    with open(filename, 'r', encoding='utf-8') as f:
        lno = 1
        for line in f:
            current = has_event(line)
            if current != '':
                if last != '' and last_lno > 0 and lno - last_lno < 5:
                    has_find = True
                    result += str(last_lno) + ': ' + last + '---' + str(lno) + ': ' + current + '\r\n'
                last = current
                last_lno = lno
            lno += 1;
        if has_find:
            result = filename + ':\r\n' + result
        return result

def main():
    param = sys.argv[1]
    if os.path.isfile(param):
        arr = python_kit.get_array_from_file(param)
        out = open('./out.txt', 'w')
        for ln in arr:
            print(ln)
            res = find_and_output(ln)
            if res != '':
                out.write(res)
        out.close()
    elif os.path.isdir(param):
        objc_files = python_kit.retrieve_path(param)
        with open('./files.txt', 'w') as f:
            for name in objc_files:
                f.write(name + '\r\n')

if __name__ == '__main__':
    main()
