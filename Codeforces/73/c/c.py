import sys

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

a, b = map(int, sys.stdin.readline().split())


x = lcm(a, b)

D = (x / a) - 1
M = (x / b) - 1

if a > b:
    D += 1
elif a < b:
    M += 1

if D > M:
    print "Dasha"
elif D < M:
    print "Masha"
else:
    print "Equal"

