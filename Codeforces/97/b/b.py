import sys

a, c = map(int, sys.stdin.readline().split())

res = []
while a > 0 or c > 0:
    ad = a % 3
    a /= 3
    cd = c % 3
    c /= 3
    for i in xrange(0, 3):
        if (ad + i) % 3 == cd:
            res.append(i)
            break

ret = 0
p = 1
for d in res:
    ret += d * p
    p *= 3

print ret
