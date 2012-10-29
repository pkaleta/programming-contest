import sys

ts = int(sys.stdin.readline())

for t in xrange(ts):
    n = int(sys.stdin.readline())
    if n <= 2:
        print 0
    else:
        print n-2
