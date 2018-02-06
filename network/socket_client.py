#! /usr/bin/env python
# -*- coding: utf-8 -*-

import socket

if __name__ == "__main__":
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(('localhost', 8001))
    sock.send('0')
    #sock.send('111')

    szBuf = sock.recv(1024)
    print('recv ' + szBuf)
    sock.close()
    print('end of connect')