import sys

T = int(sys.stdin.readline())


def calc_prob(a, b, c):
    if a + b <= c:
        return (1, 1)

    if a == b:
        P = 2 * (a ** 2)
        if c <= a:
            return (c ** 2, P)
        else:
            return (2 * (a ** 2) - (a - (c - a)) ** 2, P)

    if c <= a:
        return (c ** 2, 2 * a * b)
    elif c <= b:
        return (2 * c - a, 2 * b)
    else:
        return (2 * a * b - a ** 2 + a ** 2 - (a - (c - b)) ** 2, 2 * a * b)


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


for t in xrange(T):
    a, b, c = map(int, sys.stdin.readline().split())
    if a > b:
        tmp = a
        a = b
        b = tmp
    n, d = calc_prob(a, b, c)
    g = gcd(n, d)

    print "%d/%d" % (n / g, d / g)
