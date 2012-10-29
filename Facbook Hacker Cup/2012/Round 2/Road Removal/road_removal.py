import sys
from collections import defaultdict
sys.setrecursionlimit(10000)

T = int(sys.stdin.readline())

def dfs(v, K, prev_important, t):
#    print v
    time[v] = t
    ret = 0
    visited[v] = 1
    for u in g[v]:
#        print "*", prev, v, u, prev_important, time[u]
        if visited[u] == 1 and time[u] != time[v]-1:
            cycle[prev_important] = True
        if visited[u] == 0:
            if v < K:
                ret += dfs(u, K, v, t+1)
            else:
                ret += dfs(u, K, prev_important, t+1)
    visited[v] = 2
    return ret

for t in xrange(T):
    N, M, K = map(int, sys.stdin.readline().split())
    g = defaultdict(list)
    visited = [0 for i in xrange(N)]
    time = [0 for i in xrange(N)]
    cycle = [False for i in xrange(N)]
    for i in xrange(M):
        a, b = map(int, sys.stdin.readline().split())
        g[a].append(b)
        g[b].append(a)
    for v in xrange(K):
        if visited[v] == 0:
            dfs(v, K, 0, 0)
    ret = 0
    for v in xrange(K):
        if cycle[v]:
            print "**** ", v, len(g[v])
            ret += len(g[v])-1
    print "Case #%d: %d" % (t+1, ret)
