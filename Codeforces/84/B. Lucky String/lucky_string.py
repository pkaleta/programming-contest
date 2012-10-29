import sys

n = int(sys.stdin.readline())

c = 'a'
ret = []
for i in xrange(n):
    ret.append(c)
    c = chr(ord(c)+1)
    if c == 'e':
        c = 'a'

print ''.join(ret)
