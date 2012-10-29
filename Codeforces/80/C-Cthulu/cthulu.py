import sys
import copy

n, m = map(int, sys.stdin.readline().split())
g = [[] for i in xrange(105)]
visited = [0 for i in xrange(105)]
prev = [-1 for i in xrange(105)]
cycles = 0
nvis = 0

for i in xrange(m):
    a, b = map(int, sys.stdin.readline().split())
    g[a].append(b)
    g[b].append(a)

def dfs(u):
    global nvis
    nvis += 1
    visited[u] = 1
    for i in xrange(len(g[u])):
        v = g[u][i]
        if visited[v] == 0:
            prev[v] = u
            dfs(v)
        else:
            if visited[v] == 1 and prev[u] != v:
                global cycles
                cycles += 1
    visited[u] = 2;

dfs(1)
if nvis == n and cycles == 1:
    print "FHTAGN!"
else:
    print "NO"

