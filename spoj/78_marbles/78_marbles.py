import sys

mem = {}

t = int(sys.stdin.readline())

def f(n, k):
    a = b = 1
    for i in xrange(k):
        a *= n+i
        b *= i+1
    return a/b

for x in range(t):
    n, k = map(int, sys.stdin.readline().split())
    print f(k, n-k)
