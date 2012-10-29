import sys

t = int(sys.stdin.readline())

d = {}

def solve(a, b, ps):
    if d.has_key((a, b)):
        return d[(a, b)]
    if b <= a or len(ps) == 0:
        res = 0
    elif len(ps) == 1:
        res = b - a
    elif len(ps) == 2:
        if ps[0] - a > b - ps[1]:
            res = b - a + b - ps[0] - 1
        else:
            res = b - a + ps[1] - a - 1
    else:
        res = 100000000
        for (i, p) in enumerate(ps):
            res = min(res,
                    b - a +
                    solve(a, p - 1, ps[0:i]) +
                    solve(p + 1, b, ps[i + 1:]))
    d[(a, b)] = res
    return res

for case in range(t):
    d = {}
    p, q = map(int, sys.stdin.readline().split())
    cells = map(int, sys.stdin.readline().split())

    print "Case #%d: %d" % (case + 1, solve(1, p, cells))
