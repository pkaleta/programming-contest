import sys

n = int(sys.stdin.readline())
R = map(int, sys.stdin.readline().split())

d = {}
diff = 0
for r in R:
    if d.has_key(r):
        d[r] += 1
    else:
        diff += 1
        d[r] = 1

count = 0
res = []
while len(d.keys()) >= 3:
    count += 1
    s = []
    for k in d.keys():
        s.append(k)
        d[k] -= 1
        if d[k] == 0:
            del d[k]
        if len(s) == 3:
            res.append(s)
            break

print count
for i in xrange(len(res)):
    print ' '.join(map(str, sorted(res[i])[::-1]))
