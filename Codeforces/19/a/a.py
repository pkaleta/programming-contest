import sys

n = int(sys.stdin.readline())
teams = {}

for i in xrange(n):
    team = sys.stdin.readline()[:-1]
    teams[team] = (0, 0, 0)

z = (n*(n-1))/2

def mycmp(a, b):
    n1, (p1, s1, l1) = a
    n2, (p2, s2, l2) = b
    if p1 != p2:
        return p1-p2
    x = s1-l1
    y = s2-l2
    if x != y:
        return x-y
    return s1-s2

for i in xrange(z):
    a, b = sys.stdin.readline()[:-1].split()
    t1, t2 = a.split("-")
    g1, g2 = map(int, b.split(":"))
    p1, s1, l1 = teams[t1]
    p2, s2, l2 = teams[t2]
    if (g1 > g2):
        p1 += 3
    elif (g1 < g2):
        p2 += 3
    else:
        p1 += 1
        p2 += 1
    s1 += g1
    l1 += g2
    s2 += g2
    l2 += g1
    teams[t1] = (p1, s1, l1)
    teams[t2] = (p2, s2, l2)


tmp = teams.items()
tmp = sorted(tmp, cmp=mycmp, reverse=True)

result = []
for i in xrange(n/2):
    name = tmp[i][0]
    result.append(name)
result = sorted(result)

for i in xrange(len(result)):
    print result[i]
