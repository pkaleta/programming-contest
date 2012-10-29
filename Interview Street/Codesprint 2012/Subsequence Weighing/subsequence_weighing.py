import sys

T = int(sys.stdin.readline())

for t in xrange(T):
    n = int(sys.stdin.readline())
    a = map(int, sys.stdin.readline().split())
    w = map(int, sys.stdin.readline().split())
    d = [0 for i in xrange(n)]

    for i in xrange(n):
        m = 0
        for j in xrange(i):
            if a[j] < a[i]:
                m = max(m, d[j])
        d[i] = m + w[i]

    print max(d)
