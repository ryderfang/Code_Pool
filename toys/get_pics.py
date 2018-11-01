#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import urllib
import os

PREFIX = 'http://dl.django.t.taobao.com/rest/1.0/image?fileIds='

if __name__ == "__main__":
  f = open('./toys/pics.txt')
  for line in f:
    line = line.rstrip('\n')
    url = PREFIX + line
    print(url)
    image_name = '/Users/yimu/Work/Kite/Assets/' + line + '.jpg'
    urllib.request.urlretrieve(url, image_name)
  pass
