# python_tcp_nodelay.py
# Simple Python TCP client that enables TCP_NODELAY
import socket, time
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
print('TCP_NODELAY set')
s.connect(('127.0.0.1', 9000))
s.sendall(b'hello from python\n')
time.sleep(1)
s.close()
