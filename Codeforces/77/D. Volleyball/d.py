import sys

n, m = map(int, sys.stdin.readline().split())
x, y = map(int, sys.stdin.readline().split())

dist = [{} for i in xrange(n)]

for i in xrange(m):
    u, v, w = map(int, sys.stdin.readline().split())
    u -= 1
    v -= 1

    if dist[u].has_key(v):
        dist[u][v] = min(dist[u][v], w)
    else:
        dist[u][v] = w;

    if dist[v].has_key(u):
        dist[v][u] = min(dist[v][u], w)
    else:
        dist[v][u] = w

maxDist = []
cost = []
totPrice = [float("inf") for i in xrange(n)]
totPrice[x] = 0

for i in xrange(n):
    t, c = map(int, sys.stdin.readline().split())
    cost.append(c)
    maxDist.append(t)


def dfs(u, distLeft, curPrice):
    visited[u] = True

    for v in dist[u].keys():
        if not visited[v]:
            if distLeft >= dist[u][v]:
                totPrice[v] = curPrice
                dfs(v, distLeft-dist[u][v], curPrice)

            if maxDist[u] >= dist[u][v]:
                totPrice[v] = curPrice+cost[u]
                dfs(v, maxDist[u]-dist[u][v], curPrice + cost[u])

visited = [False for i in xrange(n)]
visited[x] = True


for v in dist[x].keys():
    if maxDist[u] >= dist[x][v]:
        dfs(v, maxDist[u]-dist[u][v], cost[x])
if totPrice[y] == float('inf'):
    print -1
else:
    print totPrice[y]

