import sys
from math import log

ts = int(sys.stdin.readline())

def binsearch(l, r, test):
    print "********* L: %d R: %d ============ %d %d" % (l, r, (l+r)/2,
            test((l+r)/2))
    if l >= r:
        return l
    m = int((l+r)/2)
    if test(m):
        return binsearch(l, m, test)
    else:
        return binsearch(m+1, r, test)

def test(l, p, csqr):
    def f(x):
        return l*(csqr**x) >= p
    return f

for t in xrange(ts):
    l, p, c = map(int, sys.stdin.readline().split())

    if l*c >= p:
        print "Case #%d: 0" % (t+1)
    else:
        a = 1
        b = int(log(p, c))+1
        result = 0
        for x in xrange(a, b+1):
            if l*(c**(2**x)) >= p:
                result = x
                break
#        result = binsearch(a, b, test(l, p, c**2))
        print "Case #%d: %d" % (t+1, result)
