import sys

n, k = map(int, sys.stdin.readline().split())
p = []

for i in xrange(n):
    p.append(int(sys.stdin.readline()))

dp = [0] * (k+1)
dp[1] = p[0]
mx = p[0]
tmp = [0] * (k+1)

for i in xrange(1, n):
    tmp[0] = mx
    for j in xrange(1, k+1):
        tmp[j] = p[i] + dp[j-1]
    for j in xrange(k+1):
        mx = max(mx, tmp[j])
        dp[j] = tmp[j]

print max(*dp)
