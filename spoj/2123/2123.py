import sys

n = int(sys.stdin.readline())
while n >= 0:
    p = []
    s = 0
    for i in xrange(n):
        x = int(sys.stdin.readline())
        s += x
        p.append(x)

    if s % len(p) != 0:
        print -1
    else:
        res = 0
        packet = s/len(p)
        for i in xrange(n):
            if p[i] < packet:
                res += packet-p[i]
        print res

    n = int(sys.stdin.readline())
