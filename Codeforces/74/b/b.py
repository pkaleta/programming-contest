import sys

n, m = map(int, sys.stdin.readline().split())
grid = []
cross = []

for i in xrange(n):
    line = list(sys.stdin.readline()[:-1])
    crossLine = [False] * len(line)
    grid.append(line)
    cross.append(crossLine)


for r in xrange(n):
    for c in xrange(m):

        flag = False
        for rr in xrange(r+1, n):
            if grid[rr][c] == grid[r][c]:
                cross[rr][c] = True
                flag = True
        for cc in xrange(c+1, m):
            if grid[r][cc] == grid[r][c]:
                cross[r][cc] = True
                flag = True

        if flag:
            cross[r][c] = True

s = []
for r in xrange(n):
    for c in xrange(m):
        if not cross[r][c]:
            s.append(grid[r][c])

print ''.join(s)

