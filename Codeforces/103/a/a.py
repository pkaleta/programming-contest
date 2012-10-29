import sys

n = int(sys.stdin.readline())

a = map(int, sys.stdin.readline().split())

maxv = a[0]
maxi = 0
minv = a[0]
mini = 0
for i in xrange(1, n):
    if a[i] > maxv:
        maxv = a[i]
        maxi = i
    if a[i] <= minv:
        minv = a[i]
        mini = i

ret = maxi + (n - mini - 1)

if maxi > mini:
    ret -= 1

print ret
