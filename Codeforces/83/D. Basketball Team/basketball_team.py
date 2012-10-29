import sys

n, m, h = map(int, sys.stdin.readline().split())
s = map(int, sys.stdin.readline().split())
ss = sum(s)

def calc(n1, n2, k):
    ret = 1.0
    i = n1-k+1
    j = n2-k+1
    while i <= n1 or j <= n2:
        if i > n1: ii = 1
        else: ii = i
        if j > n2: jj = 1
        else: jj = j
        ret *= float(ii)/float(jj)
        i += 1
        j += 1
    return ret

if (ss < n):
    print "-1.0"
else:
    print 1.0-calc(ss-s[h-1], ss-1, n-1)
