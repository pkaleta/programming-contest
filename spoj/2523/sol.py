import sys

n = int(sys.stdin.readline())

for t in xrange(n):
    m, s = sys.stdin.readline()[:-1].split()
    m = int(m)-1
    print t+1, s[:m]+s[m+1:]
