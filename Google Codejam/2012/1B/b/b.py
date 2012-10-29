import sys

T = int(sys.stdin.readline())


def can_enter(x, y, tx, ty, n, m):
    if tx < 0 or tx >= m:
        return False
    if ty < 0 or ty >= n:
        return False
    if floor[y][x] + 50 > ceil[ty][tx]:
        return False
    if floor[ty][tx] + 50 > ceil[ty][tx]:
        return False
    if floor[ty][tx] + 50 > ceil[y][x]:
        return False
    return True


def solve(sx, sy, h, ceil, floor, n, m):
    Q = [(sx, sy)]
    starts = set()
    visited = [[False for i in xrange(M)] for j in xrange(N)]

    while len(Q) > 0:
        x, y = Q[0]
        #        print "#############", x, y
        Q = Q[1:]
        if visited[y][x]:
            continue
        visited[y][x] = True
        starts.add((x, y))
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            tx = x + dx
            ty = y + dy
            if can_enter(x, y, tx, ty, n, m) and not visited[ty][tx] and h + 50 <= ceil[ty][tx]:
                #                print "############", x, y, tx, ty
                Q.append((tx, ty))

                    #    print map(lambda x: (x[0], x[1]), q)
    q = [(x, y, 0, h) for x, y in starts]
    visited = [[False for i in xrange(M)] for j in xrange(N)]
    min_time = [[float('inf') for i in xrange(M)] for j in xrange(N)]

    #    print q
    while len(q) > 0:
        x, y, t, h = q[0]
        visited[y][x] = True
        #        print "***********", q[0]
        q = q[1:]
        if min_time[y][x] < t:
            continue
        min_time[y][x] = t
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            tx = x + dx
            ty = y + dy

            if not can_enter(x, y, tx, ty, n, m):
                continue

            dt = 0.0
            if h + 50 > ceil[ty][tx]:
                dh = h + 50 - ceil[ty][tx]
            else:
                dh = 0
            if dh > 0:
                dt += float(dh) / 10.0

            if max(0, (h-dh)) - floor[y][x] >= 20:
                time_to_drag = 1
            else:
                time_to_drag = 10
            dt += time_to_drag
            dh += time_to_drag * 10
            if t + dt < min_time[ty][tx]:
                q.append((tx, ty, t + dt, max(0, h - dh)))
    return min_time[n-1][m-1]


for t in xrange(T):
    H, N, M = map(int, sys.stdin.readline().split())
    ceil = [map(int, sys.stdin.readline().split()) for i in xrange(N)]
    floor = [map(int, sys.stdin.readline().split()) for i in xrange(N)]

    print "Case #%d: %f" % (t + 1, solve(0, 0, H, ceil, floor, N, M))

