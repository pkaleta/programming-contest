import sys

n, m = map(int, sys.stdin.readline().split())
g = []

for i in xrange(n):
    line = map(int, sys.stdin.readline().split())
    g.append(line)

a, b = map(int, sys.stdin.readline().split())

def check(a, b):
    res = n*m
    for i in xrange(n-a+1):
        for j in xrange(m-b+1):

            cur = 0;
            for k in xrange(a):
                for l in xrange(b):
                    cur += g[i+k][j+l] == 1
            if cur < res:
                res = cur
    return res

print min(check(a, b), check(b, a))
