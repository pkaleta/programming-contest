import sys

n = int(sys.stdin.readline())
d = {}

def solve(l, r, cells):
    if len(cells) == 0:
        return 0
    if d.has_key((l, r)):
        return d[(l, r)]

    res = float('infinity')
    for i in xrange(len(cells)):
        left = solve(l, cells[i]-1, cells[:i])
        right = solve(cells[i]+1, r, cells[i+1:])
        res = min(res, r-l+left+right)
    d[(l, r)] = res
    return res

for cs in xrange(n):
    d = {}
    p, q = map(int, sys.stdin.readline().split())
    cells = map(int, sys.stdin.readline().split())

    print "Case #%d: %d" % (cs+1, solve(1, p, cells))
