import sys

n = int(sys.stdin.readline())
a = map(int, sys.stdin.readline().split())

aa = []
res = [-1 for i in xrange(len(a))]

for i in xrange(len(a)):
    aa.append((a[i], i))

aa = sorted(aa, key = lambda x: x[0])

maxPos = aa[0][1];
res[maxPos] = -1
for i in xrange(1, len(aa)):
    v = aa[i][0]
    pos = aa[i][1]
    if pos > maxPos:
        res[pos] = -1
        maxPos = pos
    else:
        res[pos] = maxPos-pos-1

print ' '.join(map(str, res))

