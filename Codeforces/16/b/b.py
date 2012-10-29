import sys

n, m = map(int, sys.stdin.readline().split())

t = []

for i in xrange(m):
    a, b = map(int, sys.stdin.readline().split())
    t.append((a, b))

t = sorted(t, key=lambda x: x[1], reverse=True)

result = 0
i = 0
while i < m and n > 0:
    if n < t[i][0]:
        result += n*t[i][1]
        n = 0
    else:
        result += t[i][0]*t[i][1]
        n -= t[i][0]
    i += 1

print result
