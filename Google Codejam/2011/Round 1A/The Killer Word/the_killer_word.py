import sys

T = int(sys.stdin.readline())

length = [[] for i in xrange(1, 11)]

for t in xrange(T):
    N, M = map(int, sys.stdin.readline().split())
