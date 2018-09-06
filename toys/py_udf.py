#! /usr/bin/env python2
# -*- coding: utf-8 -*-

import re

class get_blur(object):
    def evaluate(self, result, label):
        pieces = result.split(' ')
        # print(pieces)
        if len(pieces) != 4:
            return '' 
        ret = ''
        for i in range(4):
            if pieces[i].count(label):
                # print(i)
                if i < 2:
                    t = pieces[1-i]
                else:
                    t = pieces[5-i]
                ret = re.search(r"\d+\.\d+([Ee]-?\d+)?", t).group()
                ret = '{:.10f}'.format(float(ret))
                break
        return str(ret)
            
if __name__ == '__main__':
    sol = get_blur()
    print(sol.evaluate('[{"label":"blur" "confidence":0.024821362} {"confidence":0.97517866 "label":"clear"}]', 'clear'))
    print(sol.evaluate('[{"label":"clear" "conf":0.99990034103393555} {"label":"blur" "conf":9.9615579529199749e-05}]', 'clear'))
    print(sol.evaluate('[{"label":"clear" "conf":0.99991273880004883} {"label":"blur" "conf":8.7209766206797212e-05}]', 'blur'))

