import sys

code = sys.stdin.readline()[:-1]

d = {}
for i in xrange(10):
    digit = sys.stdin.readline()[:-1]
    d[digit] = i

pwd = ""
for i in xrange(0, 8):
    a = i*10
    b = i*10+10
    f = code[a:b]
    pwd += str(d[f])

print pwd
