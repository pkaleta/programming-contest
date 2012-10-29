import sys

T = int(sys.stdin.readline())

def check(n, l, h, p):
    for f in xrange(l, h+1):
        can = True
        for j in xrange(n):
            if p[j] % f != 0 and f % p[j] != 0:
                can = False
                break
        if can:
            return (True, f)
    return (False, -1)

for t in xrange(T):
    n, l, h = map(int, sys.stdin.readline().split())
    p = map(int, sys.stdin.readline().split())

    test, f = check(n, l, h, p)
    if test:
        print "Case #%d: %d" % (t+1, f)
    else:
        print "Case #%d: NO" % (t+1)

