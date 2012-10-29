import sys

C = int(sys.stdin.readline())
dp = {}
apples = []

def solve(n):
    if dp.has_key(n):
        return dp[n]
    ret = float('inf')
    if n < 0:
        return ret
    if n == 0:
        return 0
    for (w, p) in apples:
        ret = min(ret, p + solve(n-w))
    dp[n] = ret
    return ret

for c in xrange(C):
    n, k = map(int, sys.stdin.readline().split())
    dp = {}
    apples = []
    prices = map(int, sys.stdin.readline().split())
    for i in xrange(k):
        if prices[i] != -1:
            apples.append((i+1, prices[i]))
    ret = solve(k)
    if ret == float('inf'):
        print -1
    else:
        print ret
