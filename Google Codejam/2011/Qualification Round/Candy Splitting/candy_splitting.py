import sys

ts = int(sys.stdin.readline())

for t in xrange(ts):
    n = int(sys.stdin.readline())
    c = map(int, sys.stdin.readline().split())

    tmp = 2 ** n
    result = -1

    for i in xrange(1, tmp-1):
        s = 0
        p = 0
        r = 0
        for j in xrange(n):
            if ((1 << j) & i) >= 1:
                s ^= c[j]
                r += c[j]
            else:
                p ^= c[j]

        if s == p and r > result:
            result = r

    if result != -1:
        print "Case #%d: %d" % (t+1, result)
    else:
        print "Case #%d: NO" % (t+1)

