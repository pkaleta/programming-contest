import sys

n, m = map(int, sys.stdin.readline().split())
lines = []

result = True

for i in xrange(n):
    line = sys.stdin.readline()[:-1]
    for j in xrange(1, m):
        if line[j] != line[j-1]:
            result = False
    lines.append(line)
    if len(lines) >= 2:
        if lines[i][0] == lines[i-1][0]:
            result = False

if result:
    print "YES"
else:
    print "NO"

