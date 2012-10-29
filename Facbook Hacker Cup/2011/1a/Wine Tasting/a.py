import sys

def fact(n):
    if n == 0:
        return 1
    return n * fact(n-1)

newton = [[0 for i in xrange(200)] for j in xrange(200)]
for i in xrange(0, 105):
    newton[i][0] = 1
for i in xrange(1, 105):
    for j in xrange(1, 105):
        newton[i][j] = newton[i-1][j-1]+newton[i-1][j]

d = {0: 1, 1: 0}
def calc(n):
    if d.has_key(n):
        return d[n]
    d[n] = (n-1)*(calc(n-1) + calc(n-2))
    return d[n]

MOD = 1051962371

n = int(sys.stdin.readline())

for i in xrange(n):
    g, c = map(int, sys.stdin.readline().split())
    result = 1
    for j in xrange(2, g-c+1):
        result += newton[g][j]*calc(j)
    print result % MOD

