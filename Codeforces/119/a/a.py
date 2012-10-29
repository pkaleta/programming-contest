import sys

n, a, b, c = map(int, sys.stdin.readline().split())

ret = 0
for i in xrange(0, n+1):
    if a * i > n:
        break
    for j in xrange(0, n+1):
        if a * i + b * j > n:
            break
        left = n - (a * i + b * j)
        if left % c == 0:
            k = left // c
        else:
            continue
        ret = max(ret, i + j + k)

print ret
