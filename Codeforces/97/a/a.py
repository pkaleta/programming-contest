import sys

n = int(sys.stdin.readline())
p = map(int, sys.stdin.readline().split())
pp = [-1 for i in xrange(n)]

for i in xrange(n):
    pp[p[i]-1] = i+1

print ' '.join(map(str, pp))
