import sys
from math import sqrt

x1, y1, r1 = map(int, sys.stdin.readline().split())
x2, y2, r2 = map(int, sys.stdin.readline().split())

eps = 10**-6

def swap(a, b):
    tmp = a
    a = b
    b = tmp

if r1 < r2:
    swap(x1, x2)
    swap(y1, y2)
    swap(r1, r2)

def dist(x1, y1, x2, y2):
    a = abs(x1-x2)
    b = abs(y1-y2)
    return sqrt(a**2 + b**2)

center_dist = dist(x1, y1, x2, y2)

# 2 calkowicie w srodku 1
ret = float('inf')
if r1 + eps > center_dist + r2:
    ret = (r1-(center_dist+r2)) / 2.
# 2 lezy czesciowo w 1 lub na okregu 1
elif r1 + eps > center_dist:
    ret = (center_dist + r2 - r1) / 2.
# okregi sie przecinaja
elif r1 + r2 + eps > center_dist:
    ret = 0.0
else:
    ret = (center_dist - r1 - r2) / 2.

print ret
