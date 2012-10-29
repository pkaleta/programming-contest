import sys

n = int(sys.stdin.readline())

x = [0 for i in xrange(n)];
c = [0 for i in xrange(n)];

y = [[0, 0] for i in xrange(n)]

for i in xrange(n):
    y[i][0], y[i][1] = map(int, sys.stdin.readline().split())

def mycmp(a, b):
    return a[0]-b[0]

y = sorted(y, cmp=mycmp)
for i in xrange(n):
    x[i] = y[i][0]
    c[i] = y[i][1]

INFTY = float('inf')

t = [[INFTY, INFTY] for i in xrange(n)]
last = [INFTY for i in xrange(n)]

t[0][0] = c[0]
last[0] = x[0]

for i in xrange(1, n):
    t[i][0] = c[i]+min(t[i-1][0], t[i-1][1])

    a = t[i-1][0]+x[i]-x[i-1]
    b = t[i-1][1]+x[i]-last[i-1]
    if a <= b:
        last[i] = x[i-1]
        t[i][1] = a
    else:
        last[i] = last[i-1]
        t[i][1] = b

print t
print last

print min(t[n-1][0], t[n-1][1])
