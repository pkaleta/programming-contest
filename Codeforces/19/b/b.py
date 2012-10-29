import sys

n = int(sys.stdin.readline())

items = [(-1, -1)]

INFINITY = float("inf")
result = 0

for i in xrange(n):
    t, c = map(int, sys.stdin.readline().split())
    result += c
    items.append((t, c))

dp = [[(0, INFINITY) for j in xrange(n+1)] for i in xrange(n+1)]

for i in xrange(n+1):
    dp[i][0] = (0, 0)

for i in xrange(1, n+1):
    for j in xrange(1, n+1):
        tkn, res = dp[i][j] = dp[i-1][j]
        if j-items[i][0] >= 0:
            ptkn, pres = dp[i-1][j-items[i][0]]
            tmp = pres+items[i][1]
            if tmp < res or (tmp == res and ptkn+1 > tkn):
                dp[i][j] = (ptkn+1, pres+items[i][1])

for i in xrange(1, n+1):
    tkn, res = dp[n][i]
    if tkn+i >= n:
        result = min(result, res)
print result

#for i in xrange(n+1):
#    for j in xrange(n+1):
#        print dp[i][j],
#    print
