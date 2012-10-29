import sys

def calc(n, m):
    return ((n+1)/2)*((m+1)/2)+(m/2)*(n/2)

nn, mm = map(int, sys.stdin.readline().split())
x = int(sys.stdin.readline())

n = nn-2*(x-1)
m = mm-2*(x-1)

if n <= 0 or m <= 0:
    print 0
else:
    res = calc(n, m)
    if n-2 > 0 and m-2 > 0:
        res -= calc(n-2, m-2)
    print res
