import sys
from math import ceil

n, m = map(int, sys.stdin.readline().split())

if n == 1:
    print m
elif m == 1:
    print n
elif n == 2:
    r = 0
    if m % 4 == 1:
        r = 2
    elif m % 4 == 2:
        r = 4
    elif m % 4 == 3:
        r = 4
    print max(m, m/4 * 4 + r)
elif m == 2:
    r = 0
    if n % 4 == 1:
        r = 2
    elif n % 4 == 2:
        r = 4
    elif n % 4 == 3:
        r = 4
    print max(n, n/4 * 4 + r)
elif (n * m) % 2 == 0:
    print (n*m)/2
else:
    print (n*m)/2+1
