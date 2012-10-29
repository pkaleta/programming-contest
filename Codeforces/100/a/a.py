import sys
from math import pi
from math import radians, sin

n, R, r = map(int, sys.stdin.readline().split())
eps = 10e-8

if n == 1:
    if r <= R:
        print "YES"
    else:
        print "NO"
else:
    if r / sin(pi / n) - eps <= R-r:
        print "YES"
    else:
        print "NO"
