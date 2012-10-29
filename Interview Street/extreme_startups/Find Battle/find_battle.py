import sys

n, q = map(int, sys.stdin.readline().split())
points = []

for i in xrange(n):
    id, x, y = map(int, sys.stdin.readline().split())
    points.append((id, x, y))

points = sorted(points, key=lambda (id, x, y): x)


def dist(x1, y1, x2, y2):
    return (abs(x2-x1)**2) + (abs(y2-y1)**2)


def get_closest((lid, lx, ly), (rid, rx, ry)):
    d1 = dist(x, y, lx, ly)
    d2 = dist(x, y, rx, ry)
    if d1 == d2:
        return (max(lid, rid), lx, ly)
    elif d1 < d2:
        return (lid, lx, ly)
    else:
        return (rid, rx, ry)



def closest(x, y, l, r, points):
    #    print '***********', l, r
    if l == r:
        return points[l]
    if l+1 == r:
        return get_closest(points[l], points[r])

    mid = (l + r) // 2
    p1 = closest(x, y, l, mid, points)
    p2 = closest(x, y, mid+1, r, points)
    return get_closest(p1, p2)


for i in xrange(q):
    x, y = map(int, sys.stdin.readline().split())
    (id1, _, _) = closest(x, y, 0, len(points)-1, points)
    points2 = []
    #    print "**********"
    for id, xx, yy in points:
        if id != id1:
            points2.append((id, xx, yy))
    (id2, _, _) = closest(x, y, 0, len(points2)-1, points2)
    print id1, id2
