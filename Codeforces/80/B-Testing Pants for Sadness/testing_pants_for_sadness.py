import sys

n = int(sys.stdin.readline())
a = map(int, sys.stdin.readline().split())
ret = 0
for i in xrange(n):
    if (a[i] == 1):
        ret += 1
    else:
        ret += (a[i]-1)*i+a[i]
print ret
