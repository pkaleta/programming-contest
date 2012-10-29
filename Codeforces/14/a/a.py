import sys

n, m = map(int, sys.stdin.readline().split())

paper = []
minx = miny = 100
maxx = maxy = -1

for i in xrange(n):
    line = sys.stdin.readline()[:-1]
    paper.append(line);
    for j in xrange(m):
        if line[j] == '*':
            if i < miny:
                miny = i
            if i > maxy:
                maxy = i
            if j < minx:
                minx = j
            if j > maxx:
                maxx = j

for i in xrange(miny, maxy+1):
    print paper[i][minx:maxx+1]



