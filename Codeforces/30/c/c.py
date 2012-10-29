import sys

maxn = 1005

n = int(sys.stdin.readline()[:-1])
points = []

def dist(a, b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])

for i in xrange(n):
    xx, yy, tt, pp = map(float, sys.stdin.readline().split())
    points.append((int(xx), int(yy), int(tt), float(pp)))

if n == 1:
    print "%.10f" % points[0][3]
else:

    def comp(a, b):
        return a[2]-b[2]

    tmp = (sorted(points, cmp=comp))
    points = [points[1]]
    points.extend(tmp)

    yes = [0.0 for i in xrange(n+1)]
    no = [0.0 for i in xrange(n+1)]

    def binsearch():
        pass

    def find(i):
        for j in range(i-1, 0, -1):
            if dist(points[i], points[j]) <= points[i][2]-points[j][2]:
                return j
        return 0

    result = 0.0
    yes[1] = points[1][3]

    for i in xrange(2, n+1):
        j = find(i)
        yes[i] = max(yes[j], no[j])+points[i][3]
        no[i] = max(yes[i-1], no[i-1])

        result = max(result, max(yes[i], no[i]))

    print "%.10f" % result
