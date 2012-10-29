import sys

n = int(sys.stdin.readline())
t = []

j = 2
d = 2
for i in xrange(2, n+1):
    if (j == 0):
        t.append(n)
    else:
        t.append(j)
    j = (j+d)%n
    d += 1

s = ""
for i in t:
    s += "%d " % i

print s
