import sys

T = int(sys.stdin.readline())

def solve(vines, i, D, dist):
    j = i + 1
    ret = False
    if vines[i][0] + min(dist, vines[i][1]) >= D:
        return True
    while j < len(vines) and vines[j][0] <= vines[i][0] + min(dist, vines[i][1]):
        if solve(vines, j, D, vines[j][0]-vines[i][0]):
            return True
        j += 1
    return False

for t in xrange(T):
    N = int(sys.stdin.readline())
    vines = []
    for i in xrange(N):
        vine = map(int, sys.stdin.readline().split())
        vines.append(vine)
    D = int(sys.stdin.readline())

    vines = sorted(vines)

    ret = solve(vines, 0, D, min(vines[0][1], vines[0][0]))

    print "Case #%d: %s" % (t+1, "YES" if ret else "NO")
