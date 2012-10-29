import sys

T = int(sys.stdin.readline())

sys.setrecursionlimit(100000)

def dfs(v, p, color):
    color[v] = 1
    for u in p[v]:
        if color[u] == 2:
            return True
        if color[u] == 0:
            ret = dfs(u, p, color)
            if ret:
                return True
    color[v] = 2
    return False

for t in xrange(T):
    N = int(sys.stdin.readline())
    p = []
    for i in xrange(N):
        line = sys.stdin.readline().split()
        p.append(map(lambda s: int(s)-1, line[1:]))

    ret = False
    color = [0 for i in xrange(N)]
    for v in xrange(N):
        color = [0 for i in xrange(N)]
        if color[v] == 0:
            if dfs(v, p, color):
                ret = True
                break

    print "Case #%d: %s" % (t + 1, "Yes" if ret else "No")

