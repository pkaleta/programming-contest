import sys
from bisect import bisect

s1 = sys.stdin.readline()[:-1]
s2 = sys.stdin.readline()[:-1]
d = [[] for i in xrange(30)]


for i in xrange(len(s1)):
    c = ord(s1[i])-ord('a')
    l = d[c]
    l.append(i)
    d[c] = l

last = -1
ret = 1;

for i in xrange(len(s2)):
    c = ord(s2[i])-ord('a')
    pos = d[c]

    if len(pos) == 0:
        ret = -1
        break

    i = 0
    i = bisect(pos, last, 0, len(pos))

    if i >= len(pos):
        ret += 1
        last = pos[0]
    else:
        last = pos[i]

print ret


