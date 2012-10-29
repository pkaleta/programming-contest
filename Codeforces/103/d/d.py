import sys
from collections import deque

def dijkstra(G,start,n, end=None):
	D = [float('inf') for i in xrange(n+1)]	# dictionary of final distances
        vis = [False for i in xrange(n+1)]

        D[s] = 0
        vis[s] = True

	Q = deque()   # est.dist. of non-final vert.

        Q.append(s);

        while Q:
            u = Q.popleft()
            for v, w in G[u].items():
                if D[u] + w < D[v]:
                    D[v] = D[u] + w
                    if not vis[v]:
                        Q.append(v)
                        vis[v] = True

	return D

n, m, s = map(int, sys.stdin.readline().split())
G = {}
es = []
for i in xrange(m):
    u, v, w = map(int, sys.stdin.readline().split())
    if not G.has_key(u):
        G[u] = {}
    if not G.has_key(v):
        G[v] = {}
    G[u][v] = w
    G[v][u] = w
    es.append((u, v, w))

l = int(sys.stdin.readline())

D = dijkstra(G, s, n)

ret = 0

for u, v, w in es:
    du = l - D[u]
    dv = l - D[v]
    if D[u] < l and D[u] + w > l and D[u] + du <= D[v] + w-dv:
        ret += 1
    if D[v] < l and D[v] + w > l and D[v] + dv <= D[u] + w-du:
        if dv != w-du:
            ret += 1

for u in xrange(1, n+1):
    if D[u] == l:
        ret += 1

print ret
