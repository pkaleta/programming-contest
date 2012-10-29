import sys
from math import sqrt

x, y = map(int, sys.stdin.readline().split())

r = sqrt(x*x+y*y)
c = int(r)

if r == c:
    print "black"
else:
    if x*y > 0:
        if c % 2 == 0:
            print "black"
        else:
            print "white"
    else:
        if c % 2 == 0:
            print "white"
        else:
            print "black"

