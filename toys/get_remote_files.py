#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
http://photography.denti-pro.com/wp-content/uploads/
'''

import re
import requests
import os
import urllib.request

images = []

def get_files(pre_url):
    print(pre_url)
    if pre_url[-4] == '.':
        images.append(pre_url)
        return
    r = requests.get(pre_url)
    data = r.text
    #print(data)
    link_list = re.findall(r"(?<=href=\").+?(?=\")|(?<=href=\').+?(?=\')", data)
    idx = 0
    for url in link_list:
        if url[0] == '/':
            url = url[1:]
        url = pre_url + url
        #print(url)
        if idx > 0:
            get_files(url)
        idx = idx + 1
    pass

if __name__ == '__main__':
    #get_files("http://photography.denti-pro.com/wp-content/uploads/")
    #print(images)
    print(len(images))
    # f = open('/Users/fangr/images.txt', 'w')
    # for img in images:
    #     f.write(img + '\r\n')
    # f.close()
    f = open('/Users/fangr/images.txt', 'r')
    for line in f:
        line = line.rstrip('\n')
        images.append(line)
        filename = '/Users/fangr/denti/' + os.path.basename(line)
        urllib.request.urlretrieve(line, filename)
    print(len(images))

    # path = '/Users/fangr/'
    # filename = path + os.path.basename(img)
    # urllib2.urlretrieve(url, filename)

