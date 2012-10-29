import sys

n = int(sys.stdin.readline())
a = []

for i in xrange(n):
    a.append(int(sys.stdin.readline()))

a = sorted(a)

ret = 0;
i = 0

while n > 1:
    #    print a, n

    for i in xrange(n // 2):
        a[i] = a[2*i] + a[2*i+1]
        ret += a[i]
    if n % 2 == 1:
        a[n // 2] = a[-1]
    n = (n // 2) + (n % 2 == 1)
    a = sorted(a[:n])

print ret
