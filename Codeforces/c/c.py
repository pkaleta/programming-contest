import sys

n, m = map(int, sys.stdin.readline().split())
words = []
for i in xrange(n):
    words.append(sys.stdin.readline().strip())

ret = 1
for i in xrange(m):
    d = {}
    for j in xrange(n):
        d[words[j][i]] = True
    ret = (ret * len(d.keys())) % 1000000007
print ret
