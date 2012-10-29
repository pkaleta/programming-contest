import sys
from collections import defaultdict

MOD = 10 ** 9
INF = float('inf')
N, M = map(int, sys.stdin.readline().split())
g = defaultdict(list)
gg = defaultdict(list)

for i in xrange(M):
    a, b = map(int, sys.stdin.readline().split())
    g[b].append(a)
    gg[a].append(b)

paths_count = defaultdict(int)
paths_count[1] = 1
color = defaultdict(int)

def is_cycle(u):
    if color[u] == 2:
        return False
    if color[u] == 1:
        return True
    color[u] = 1
    ret = False
    for v in g[u]:
        ret = ret or is_cycle(v)
    color[u] = 2
    return ret

def dfs(v):
    if v in paths_count:
        return paths_count[v]
    ret = 0
    for u in g[v]:
        ret += dfs(u)
    paths_count[v] = ret
    return ret

visited = defaultdict(bool)
def is_cycle2(u):
    if u == N and visited[u]:
ksfad        return True
    if not visited[u]:
        visited[u] = True
        ret = False
        for v in gg[u]:
            ret = ret or is_cycle2(v)
        return ret
    return False


if is_cycle(N) or is_cycle2(N):
    print "INFINITE PATHS"
else:
    print dfs(N) % MOD
