import sys

n, w, m = map(int, sys.stdin.readline().split())

p = {}
for i in xrange(m):
    p[i] = []

bs = [w for i in xrange(n)]
limit = (float(w)*float(n))/float(m)

cur = 0
milk = [0 for i in xrange(m)]
ok = True
maxCups = -1
end = False
eps = 10**(-6)

for i in xrange(n):

    cups = 0
    while not end and bs[i]-eps > 0.0:
        cups += 1
        need = limit-milk[cur]
#        print 
#        print str(bs[i]), need
        if bs[i]+eps < need:
#            print "1wlewam osobie %d %f mleka z butelki %d" % (cur, bs[i], i)
            milk[cur] += bs[i]
            p[cur].append((i, bs[i]))
            break
        else:
#            print "2wlewam osobie %d %f mleka z butelki %d" % (cur, need, i)
            milk[cur] = limit
            p[cur].append((i, need))
            bs[i] -= need
            if cur == m-1:
                end = True
                break
            cur += 1

#    print "bottle %d cups %d" %(i, cups)

    maxCups = max(cups, maxCups)


if maxCups > 2:
    print "NO"
else:
    print "YES"
    for k in p.keys():
        s = ""
        for (b, v) in p[k]:
            s += "%d %.6f " % (b+1, v)
        print s



