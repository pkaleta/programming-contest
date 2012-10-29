import sys

ts = int(sys.stdin.readline())

def check(w1, w2):
    a1 = w1[0]; a2 = w1[1];
    b1 = w2[0]; b2 = w2[1];
    return (a1 < b1 and a2 > b2) or (a1 > b1 and a2 < b2)

for t in xrange(ts):
    w = []
    n = int(sys.stdin.readline())
    for i in xrange(n):
        a, b = map(int, sys.stdin.readline().split())
        w.append((a, b))

    result = 0
    for i in xrange(n):
        for j in xrange(i, n):
            if check(w[i], w[j]):
                result += 1

    print "Case #%d: %d" % (t+1, result)


