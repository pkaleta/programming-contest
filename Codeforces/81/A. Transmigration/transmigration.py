import sys

n, m, k = sys.stdin.readline().split()
n = int(n)
m = int(m)
k = float(k)

d = {}

for i in xrange(n):
    name, exp = sys.stdin.readline().split()
    exp = int(exp)
    if k*float(exp) >= 100:
        d[name] = int(k*float(exp)+0.000000001)

for i in xrange(m):
    name = sys.stdin.readline()[:-1]
    if not d.has_key(name):
        d[name] = 0

skills = sorted(d.items(), key = lambda (k, v): k)

print len(skills)
for (name, exp) in skills:
    print name, exp

