import sys

T = int(sys.stdin.readline())

def dist(p, a, c):
    return a[p%c]


for tc in xrange(T):
    line = map(int, sys.stdin.readline().split())
    l, t, n, c = line[:4]
    a = line[4:]
    suma = 2*sum(a)

    tmp = 0
    for i in xrange(n):
        tmp += 2*dist(i, a, c)

    if l == 0 or tmp <= t:
        print "Case #%d: %d" % (tc+1, tmp)
        continue

#    print "**********", t, suma

    ileCalych = t / suma
    odl = ileCalych * suma

#    print "odl: ", odl
#    print "ilecalych: ", ileCalych

    first = ileCalych*c
    while first <= n-1 and odl + 2*dist(first, a, c) <= t:
        odl += 2*dist(first, a, c)
        first += 1

#    print "first: ", first

    time = t

    zysk = [dist(first, a, c)-((t-odl)/2)]
    for i in xrange(first+1, n):
        zysk.append(dist(i, a, c))

    zysk = sorted(zysk)[::-1]

#    print zysk

    for i in xrange(len(zysk)):
        if i < l:
            time += zysk[i]
        else:
            time += zysk[i]*2

    print "Case #%d: %d" % (tc+1, time)

