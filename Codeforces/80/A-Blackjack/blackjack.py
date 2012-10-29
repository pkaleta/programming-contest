import sys

n = int(sys.stdin.readline())

d = {}
for i in xrange(2, 11):
    d[i] = 4;
d[10] += 11;
d[11] = 4
d[1] = 4

if not d.has_key(n-10):
    print 0
else:
    print d[n-10]
