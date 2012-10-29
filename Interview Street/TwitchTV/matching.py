import sys
from math import factorial

MOD = 1000000007

n = int(sys.stdin.readline())

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

a = 1
b = 1
ret = 1
for k in xrange(2, n+1):
    a *= n + k
    if a % k == 0:
        a /= k
    else:
        b *= k

print (a/b) % MOD
