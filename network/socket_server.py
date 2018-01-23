#! /usr/bin/env python
# -*- coding: utf-8 -*-

import socket

if __name__ == "__main__":
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("create socket success!")

        sock.bind(('localhost', 8001))
        print("bind socket success!")

        sock.listen(5)
        print("listen success!")
    except:
        print("init socket error!")

    while True:
        print("listen for client...")
        conn, addr = sock.accept()
        print("get client")
        print(addr)

        conn.settimeout(5)
        szBuf = conn.recv(1024)
        print("recv: " + szBuf)
        if "0" == szBuf:
            conn.send('exit')
        else:
            conn.send('welcome client!')
        
        conn.close()
        print('end of service')
