import sys

INF = float('inf')

n, m = map(int, sys.stdin.readline().split())

p = map(int, sys.stdin.readline().split())

match = [[False for i in xrange(n)] for i in xrange(n)]

for i in xrange(m):
    a, b = map(int, sys.stdin.readline().split())
    match[a-1][b-1] = True
    match[b-1][a-1] = True



ret = INF
for i in xrange(n):
    for j in xrange(i, n):
        for k in xrange(j, n):
            if match[i][j] and match[j][k] and match[k][i]:
                ret = min(ret, p[i]+p[j]+p[k])

if ret == INF:
    print "-1"
else:
    print ret

