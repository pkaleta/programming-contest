import sys

m = int(sys.stdin.readline())

r = [[False for i in xrange(5)] for i in xrange(5)]

for i in xrange(m):
    a, b = map(int, sys.stdin.readline().split())
    r[a-1][b-1] = True
    r[b-1][a-1] = True


found = False
for i in xrange(5):
    for j in xrange(5):
        for k in xrange(5):
            if i != j and i != k and j != k:
                found = found or (r[i][j] and r[j][k] and r[k][i]) or ((not
                        r[i][j]) and (not r[j][k]) and (not r[k][i]))


if found:
    print "WIN"
else:
    print "FAIL"

