import sys

n, h = map(int, sys.stdin.readline().split())

d = {}

def f(n, h):
    if n == 0 and h == 0:
        return 1
    if n == 0 or h == 0:
        return 0
    if d.has_key((n, h)):
        return d[(n, h)]
    r = 0
    for m in xrange(1, n+1):
        s1 = s2 = 0
        for i in xrange(0, h):
            s1 += f(n-m, i)
        for i in xrange(0, h-1):
            s2 += f(m-1, i)
        r += f(m-1, h-1)*s1+f(n-m, h-1)*s2
    d[(n, h)] = r
    return r

r = 0
for i in xrange(h, n+1):
    r += f(n, i)
print r
