import sys

T = int(sys.stdin.readline())

def calc(S, R, B, E, t):
    diff = float(E-B)
    if diff == 0:
        return (0, t)
    if t > 0:
        res = 0
        dist = float(R)*float(t)
        if dist >= diff:
            res = float(diff) / float(R)
            t -= res
        else:
            left = diff-dist
            res = t + float(left) / float(S)
            t = 0

        return (res, t)

    else:
        return (float(diff) / float(S), 0)


for tc in xrange(T):
    X, S, R, t, N = map(int, sys.stdin.readline().split())
    ws = []
    dist = X

    for i in xrange(N):
        B, E, s = map(int, sys.stdin.readline().split())
        dist -= E-B
        ws.append((B, E, s))

    (res, t) = calc(S, R, 0, dist, t)

    ws = sorted(ws, key = lambda w : w[2])

    for i in xrange(N):
        B, E, s = ws[i]
        (time, t) = calc(S+s, R+s, B, E, t)
        res += time

    print "Case #%d: %s" % (tc+1, res)


