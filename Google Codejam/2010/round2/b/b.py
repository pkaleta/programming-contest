import sys
from math import log

T = int(sys.stdin.readline())
M = []
P = 0
prices = []
INF = float('infinity')
mem = {}

def getLostMatches(a, b):
    return min(M[a:b])

def getLevel(a, b):
    return int(log(b-a, 2))

def getPrice(a, b, l):
    return prices[l-1][a/(2**l)]

def calc(a, b, m):
    lostMatches = getLostMatches(a, b)
    if m > lostMatches:
        return INF

    if b-2 == a:
        if lostMatches == m:
            return getPrice(a, b, 1);
        elif lostMatches-1 == m:
            return 0
        else:
            return INF

    if mem.has_key((a, b, m)):
        return mem[(a, b, m)]

    level = getLevel(a, b)
    mid = a+(b-a)/2

    # z placeniem
    tmp = INF
    glml = getLostMatches(a, mid)
    glmr = getLostMatches(mid, b)
    for i in xrange(max(m, glml-level), glml+1):
        for j in xrange(max(m, glmr-level), glmr+1):
            tmp = min(tmp, calc(a, mid, i) + calc(mid, b, j))
    buying = getPrice(a, b, level) + tmp

    tmp = INF
    for i in xrange(max(m+1, glml-level), glml+1):
        for j in xrange(max(m+1, glmr-level), glmr+1):
            tmp = min(tmp, calc(a, mid, i) + calc(mid, b, j))
    notBuying = tmp

    res = min(buying, notBuying)
    mem[(a, b, m)] = res

    return res


for t in xrange(T):
    M = []
    P = int(sys.stdin.readline())
    prices = []
    mem = {}

    M = map(int, sys.stdin.readline().split())
    for i in xrange(P):
        line = map(int, sys.stdin.readline().split())
        prices.append(line)

    res = INF
    for p in xrange(P+1):
        res = min(res, calc(0, 2**P, p))

    print "Case #%d: %d" % (t+1, res)
