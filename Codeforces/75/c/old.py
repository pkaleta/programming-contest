import sys

s1 = sys.stdin.readline()[:-1]
s2 = sys.stdin.readline()[:-1]
d = [[] for i in xrange(30)]

def bs(x, xs, l, r):
    while l+1 != r and l != r:
        m = (l+r)/2
        if xs[m] > x:
            r = m
        else:
            l = m

    return l


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
    i = bs(last, pos, 0, len(pos))

    if i == len(pos)-1:
        if last < pos[i]:
            last = pos[i]
        else:
            ret += 1
            last = pos[0]
    elif i == 0:
        if last < pos[i]:
            last = pos[i]
        else:
            last = pos[i+1]
    else:
        if last < pos[i]:
            last = pos[i]
        else:
            last = pos[i+1]

print ret


