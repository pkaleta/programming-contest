import sys

T = int(sys.stdin.readline())

EPS = 10**(-6)

def insert(points, x):
    i = 0
    sx = -1
    sy = -1
    while True:
        x0, y0 = points[i]
        if x0 == x:
            sx = x0
            sy = y0
            break

        x1, y1 = points[i+1]
        if x0 < x and x < x1:
            sx = x
            sy = y0+float(y1-y0)/float(x1-x0)*float(x-x0)
            break
        i += 1
    return (sx, sy)



def area(ps, xe):
    points = sorted(ps, key = lambda (x, y): x)

    last = insert(points, xe)

    points = filter(lambda (x, y): x <= xe, points)

    if (points[len(points)-1][0] != xe):
        points.append(last)
#    print points, "last: ", last

    res = 0.0
    for i in xrange(len(points)-1):
        (x0, y0) = points[i]
        (x1, y1) = points[i+1]
        res += (y0+y1) * (x1-x0) / 2.0

    return res


def calcArea(lower, upper, x):
    return area(upper, x) - area(lower, x)



def findCut(lower, upper, seekArea, w):
    curArea = 0.0
    cut = -1.0

    l = 0.0
    u = float(w)
    while curArea + EPS < seekArea or seekArea < curArea - EPS:
        cut = (l+u) / 2.0
        curArea = calcArea(lower, upper, cut)
        if curArea + EPS > seekArea:
            u = cut
        elif curArea + EPS < seekArea:
            l = cut
        else:
            break

    return cut


for t in xrange(T):
    w, l, u, g = map(int, sys.stdin.readline().split())
    lower = []
    upper = []
    for i in xrange(l):
        x, y = map(int, sys.stdin.readline().split())
        lower.append((x, y+1000))

    for i in xrange(u):
        x, y = map(int, sys.stdin.readline().split())
        upper.append((x, y+1000))

    cuts = []
    totalArea = calcArea(lower, upper, w)

    pieceArea = totalArea / g

    for i in xrange(1, g):
        cuts.append(findCut(lower, upper, i * pieceArea, w))

    cutsStr = '\n'.join(map(lambda x: "%f" % x, cuts))
    print "Case #%d:\n%s" % (t+1, cutsStr)



