import sys

MOD = 100003

ts = int(sys.stdin.readline())

d = {}
dd = {}

def g(l, m):
    if dd.has_key((l, m)):
        return dd[(l, m)]
    if m == 0:
        return 0
    if m == 1:
        return l
    if m > l:
        return 0
    if l == m:
        return 1
    result = 0
    for i in xrange(m-1, l):
        result += g(i, m-1)
    dd[(l, m)] = result
    return result

def f(n, x):
    if d.has_key((n, x)):
        return d[(n, x)]
    if x == 1:
        return 1
    j = n-x
    result = 0
    for i in xrange(1, j+1):
        if x-i >= 1:
            a = f(x, x-i)
            b = g(n-x-1, x-(x-i)-1)
            if b > 1:
                result += a*b
            else:
                result += a
    d[(n, x)] = result
    return result


for t in xrange(ts):
    n = int(sys.stdin.readline())
    result = 0
    for x in xrange(1, n):
        result += f(n, x)
    print "Case #%d: %d" % (t+1, result%MOD)
