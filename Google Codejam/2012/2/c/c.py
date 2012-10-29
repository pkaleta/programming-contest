import sys

T = int(sys.stdin.readline())

for t in xrange(T):
    N = int(sys.stdin.readline())
    a = map(lambda x: int(x)-1, sys.stdin.readline().split())

    h = 10**9
    ret = xrange(0, N)

