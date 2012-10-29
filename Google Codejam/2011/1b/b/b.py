import sys
from copy import copy

T = int(sys.stdin.readline())

def check(time, p, v, n, d):
    last = p[0]-time
    v[0] -= 1
#    print '***** last:', last, v[0]
    for i in xrange(n):
        for j in xrange(v[i]):
            if last+d <= p[i]:
                if p[i] - (last+d) < time:
                    last += d
                else:
                    last = p[i] - time
            else:
                if (last+d) - p[i] > time:
#                    print "#### %f: False" % time
                    return False
                else:
                    last += d
#            print '***** last:', last
#    print "#### %f: True" % time
    return True


for t in xrange(T):
    p = []
    v = []
    time = 0.0
    c, d = map(int, sys.stdin.readline().split())
    for i in xrange(c):
        x, y = map(int, sys.stdin.readline().split())
        p.append(x)
        v.append(y)

    l = 0
    h = 10**12
    eps = 10**(-6)

#    print check(0.500044, p, v, c, d)

    while l + eps < h:
        print "********"
        m = (l + h) / 2.0
        if not check(m, p, copy(v), c, d):
            l = m+1
        else:
            h = m-1

    print "Case #%d: %f" % (t+1, l)


