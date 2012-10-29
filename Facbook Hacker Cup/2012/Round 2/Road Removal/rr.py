import sys

T = int(sys.stdin.readline())

for t in xrange(T):
    N, M, K = map(int, sys.stdin.readline().split())
    edges = []
    s = [set([]) for i in xrange(N)]
    for i in xrange(M):
        a, b = map(int, sys.stdin.readline().split())
        if a >= K and b >= K:
            s[a] = s[b] = s[a].union(s[b])
            not_important.add(a)
            not_important.add(b)
        edges.append((a, b))
    ret = 0
    for a, b in edges:
        if a < K or b < K:
            if a in not_important and b in not_important:
                ret += 1
            else:
                not_important.add(a)
                not_important.add(b)
    print "Case #%d: %d" % (t+1, ret)
