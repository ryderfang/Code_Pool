#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
a simple calendar toy.
- param: yyyymmdd(default - today)
"""

import sys
from datetime import datetime, date
from functools import reduce

def cal_month(dt): 
    if not isinstance(dt, date):
        print('Not date object')
        return
    print(dt.isoformat())
    wk = ['一', '二', '三', '四', '五', '六', '日']
    l1 = str(reduce(lambda x, y: x + '\t' + y, wk))
    print(l1)
    days = list(range(1, 32))
    print(days)

if __name__ == '__main__':
    dt = None
    if len(sys.argv) < 2:
        dt = date.today()
    else:
        s = sys.argv[1]
        try:
            dt = datetime.strptime(s, '%Y%m%d')
        except ValueError as e1:
            print(e1)
            try:
                dt = datetime.strptime(s, '%Y-%m-%d')
            except ValueError as e2:
                print(e2)
                print("param: yyyymmdd or yyyy-mm-dd")
        if dt != None:
            cal_month(dt.date())

