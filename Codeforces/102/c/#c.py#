import sys
from math import sqrt

n = int(sys.stdin.readline())

def triples(x):
    r = int(sqrt(x)) + 1
    ts = set([])
    ds = [1, x]
    for i in xrange(2, r+1):
        if x % i == 0:
            ds.extend([i, x / i])
    ds = sorted(ds)
    for d in ds:
        r = int(sqrt(d))+1
        i = 0
        while ds[i] <= r:
            if d % ds[i] == 0:
                ts.add(tuple(sorted([x / d, ds[i], d / ds[i]])))
            i += 1
    return list(ts)

rmax = -1
rmin = float('inf')

if n == 1:
    print 17, 17
elif n == 2:
    print 22, 25
else:
    for t in triples(n):
        a, b, c = t
        i = (a+1)*(b+2)*(c+2)
        j = (b+1)*(a+2)*(c+2)
        k = (c+1)*(a+2)*(b+2)
        keys = [i, j, k]
        for k in keys:
            rmax = max(rmax, k-n)
            rmin = min(rmin, k-n)

    print rmin, rmax
