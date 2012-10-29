import sys

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

a, b, x, y = map(int, sys.stdin.readline().split())

g = gcd(x, y)
xx = x/g
yy = y/g

if xx > a or yy > b:
    print "0 0"
else:
    m = min(a/xx, b/yy)
    print xx*m, yy*m
