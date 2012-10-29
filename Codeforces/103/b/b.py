import sys

xa1, ya1, xb1, yb1 = map(int, sys.stdin.readline().split())

xa = min(xa1, xb1)
ya = min(ya1, yb1)
xb = max(xa1, xb1)
yb = max(ya1, yb1)

points = []

for i in xrange(xa, xb+1):
    points.append((i, ya))
    points.append((i, yb))

for i in xrange(ya+1, yb):
    points.append((xa, i))
    points.append((xb, i))

used = [False for i in xrange(len(points))]

n = int(sys.stdin.readline())

def inside(x, y, xs, ys, r):
    return ((x - xs) ** 2) + ((y - ys) ** 2) <= r ** 2

for i in xrange(n):
    x, y, r = map(int, sys.stdin.readline().split())
    for j in xrange(len(points)):
        if inside(points[j][0], points[j][1], x, y, r):
            used[j] = True

print len(filter(lambda x: x != True, used))
