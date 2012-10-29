import sys

t = int(sys.stdin.readline())

for c in xrange(t):
    n, k = map(int, sys.stdin.readline().split())
    if (k+1)%(2**n) == 0:
        print "Case #%d: ON" % (c+1)
    else:
        print "Case #%d: OFF" % (c+1)
