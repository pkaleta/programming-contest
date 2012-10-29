import sys

d = int(sys.stdin.readline())
n = int(sys.stdin.readline())
a = map(int, sys.stdin.readline().split())
cur = 1
ret = 0

for i in xrange(n):
    if cur > 1:
        ret += d - cur + 1
        cur = 1
    cur += a[i]

print ret
