import sys

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

y, w = map(int, sys.stdin.readline().split())

m = max(y, w)
a = 6-(m-1)
b = 6

g = gcd(a, b)

if a == 0:
    a = 0
    b = 1

print "%d/%d" % (a/g, b/g)
