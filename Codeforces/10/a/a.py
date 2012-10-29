import sys

n, p1, p2, p3, t1, t2 = map(int, sys.stdin.readline().split())

l = []
r = []

for i in xrange(n):
    a, b = map(int, sys.stdin.readline().split())
    l.append(a)
    r.append(b)

result = (r[0]-l[0])*p1

for i in xrange(1, n):
    d = l[i]-r[i-1]
    d1 = min(d, t1)
    d -= d1
    d2 = min(d, t2)
    d3 = d-d2
    result += (r[i]-l[i]+d1)*p1+d2*p2+d3*p3

print result
