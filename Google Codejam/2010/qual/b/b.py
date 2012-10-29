import sys
from math import ceil

cs = int(sys.stdin.readline())

def nwd(a, b):
    if b == 0:
        return a
    return nwd(b, a % b)

for c in xrange(cs):
    t = map(int, sys.stdin.readline().split())
    n = t[0]
    t = t[1:]
    T = abs(t[0]-t[1])

    for i in xrange(n):
        for j in xrange(n):
            if i != j:
                T = nwd(T, abs(t[i]-t[j]))
    tmp = t[0]/T
    if tmp*T < t[0]:
        tmp += 1
    result = tmp*T-t[0]

    print "Case #%d: %d" % (c+1, result)
