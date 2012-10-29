import sys

ts = int(sys.stdin.readline())

for tc in xrange(ts):
    n, k, b, t = map(int, sys.stdin.readline().split())

    x = map(int, sys.stdin.readline().split())
    v = map(int, sys.stdin.readline().split())

    c = 0
    result = 0
    tmp = 0
    i = len(x)-1
    while i >= 0 and tmp < k:
        if v[i]*t >= b-x[i]:
            tmp += 1
            result += c
        else:
            c += 1
        i -= 1

    if tmp == k:
        print "Case #%d: %d" % (tc+1, result)
    else:
        print "Case #%d: IMPOSSIBLE" % (tc+1)



