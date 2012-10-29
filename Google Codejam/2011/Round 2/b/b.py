import sys

T = int(sys.stdin.readline())
R = 0
C = 0
D = 0
m = []

def calc(sx, sy, d):
#    print "***************", sx, sy, d
    cx = sx+(d/2)
    cy = sy+(d/2)

    if d % 2 == 0:
        cx -= 0.5
        cy -= 0.5

    rx = 0
    ry = 0
    if sx+d-1 < C and sy+d-1 < R:
        for y in xrange(sy, sy+d):
            if y == sy or y == sy+d-1:
                begin = sx+1
                end = sx+d-1
            else:
                begin = sx
                end = sx+d
            for x in xrange(begin, end):
#                print x, y
                rx += (x-cx)*(D+m[y][x])
                ry += (y-cy)*(D+m[y][x])
        return (d, rx == 0 and ry == 0)
    return (-1, False)

for t in xrange(T):
    R, C, D = map(int, sys.stdin.readline().split())
    m = []
    for r in xrange(R):
        line = map(int, list(sys.stdin.readline()[:-1]))
        m.append(line)

    res = -1
    maxD = max(R, C)+1
    for y in xrange(0, R+1):
        for x in xrange(0, C+1):
            for d in xrange(3, maxD):
                    cur, check = calc(x, y, d)
                    if check:
                        res = max(res, cur)

    if res == -1:
        print "Case #%d: IMPOSSIBLE" % (t+1)
    else:
        print "Case #%d: %d" % (t+1, res)
