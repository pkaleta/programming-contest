import sys

n = int(sys.stdin.readline())
ls = []

for i in xrange(n):
    l = map(int, sys.stdin.readline().split())
    ls.append((i+1, l))


good = []
for i in xrange(n):
    l1 = ls[i][1]

    ok = True;
    for j in xrange(n):
        l2 = ls[j][1]

        less = True
        for k in xrange(3):
            if l1[k] >= l2[k]:
                less = False
                break

        if less:
            ok = False
            break

    if ok:
        good.append((ls[i][0], l1[3]))

good = sorted(good, key = lambda (num, cost): cost)

print good[0][0]


