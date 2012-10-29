import sys

MOD = 142857

T = int(sys.stdin.readline())


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


def solve(n, r):
    if r > n - r:
        r = n - r

    num = 1
    den = 1
    j = 1
    for i in xrange(n - r + 1, n + 1):
        num *= i
        den *= j
        j += 1

    return (num / den) % MOD


for t in xrange(T):
    n, r = map(int, sys.stdin.readline().split())

    print solve(n, r)
