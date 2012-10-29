import sys

n = int(sys.stdin.readline())
c = n
res = []
for i in xrange(n, 0, -1):
    if c % i == 0:
        c = i
        res.append(str(c))

print ' '.join(res)
