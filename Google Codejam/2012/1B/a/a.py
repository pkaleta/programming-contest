import sys
from collections import defaultdict

MAX_POINTS = 100

T = int(sys.stdin.readline())
for t in xrange(T):
    line = map(int, sys.stdin.readline().split())
    N = line[0]
    J = line[1:]
    X = sum(J)


    ret = []
    for i in xrange(N):
        points = sorted(J[:i] + J[i+1:])

        j = 0
        cur = 0
        added_points = 0
        left_count = 1
        points_left = X
        while j < N-1:
            if J[i] + added_points < points[j]:
                diff = points[j] - (J[i] + added_points)
                if left_count * diff >= points_left:
                    added_points += float(points_left) / left_count
                    points_left = 0
                    break
                else:
                    added_points += diff
                    points_left -= left_count * diff
                    left_count += 1
            else:
                diff = (J[i] + added_points) - points[j]
                if diff >= points_left:
                    points_left = 0
                    break
                else:
                    points_left -= diff
                    left_count += 1
            j += 1

        if points_left > 0:
            added_points += float(points_left) / left_count

        ret.append("%.6f" % (float(added_points) / float(X) * 100.0))

    print "Case #%d: %s" % (t + 1, " ".join(ret))
