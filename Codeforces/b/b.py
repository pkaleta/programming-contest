import sys

n, m = map(int, sys.stdin.readline().split())
xc, yc = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())
steps = 0;

for i in xrange(k):
    dx, dy = map(int, sys.stdin.readline().split())
#    print "jestem w: ", xc, yc
    if dx == 0:
        p = float('inf')
    else:
        l = float(n-xc)/float(dx)
        r = float(1-xc)/float(dx)
        p = max(int(l), int(r))
    if (dx > 0 and l >= p >= r) or (dx < 0 and l <= p <= r) or dx == 0:
        if dy == 0:
            q = float('inf')
        else:
            l = float(m-yc)/float(dy)
            r = float(1-yc)/float(dy)
            q = max(int(l), int(r))
#        print "****", l, q, r
        if (dy > 0 and l >= q >= r) or (dy < 0 and l <= q <= r) or dy == 0:
###            print "################", p, q
            cur = max(0, min(p, q))
#            print "***", cur
            xc += cur * dx
            yc += cur * dy
            steps += cur
print steps
