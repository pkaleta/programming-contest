import sys

def a(n, m):
    if n == m:
        return "0.00"
    else:
        return "%.2f" % (2 ** (n+1) - 2 ** (m+1))

def b(n, m):
    num = n-m
    den = 1 << (n-m)
    tosses = (1 << (n+1)) - 2
    for i in xrange(1, n-m+1):
        num += (i + tosses) * (1 << (n-m-i))
    return "%.2f" % (num / den)


if __name__ == "__main__":
    for n in xrange(1001):
        for m in xrange(1001):
            if m <= n:
                if a(n,m) != b(n,m):
                    print "*******", n, m, a(n, m), b(n,m)
