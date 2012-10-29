import sys
from math import sqrt

T = int(sys.stdin.readline())

isPrime = [True for i in xrange(1000005)]
isPrime[0] = isPrime[1] = False
primes = []

for i in xrange(2, 1000005):
    if isPrime[i]:
        primes.append(i)
        j = i*2
        while j < 1000005:
            isPrime[j] = False
            j += i

for t in xrange(T):
    n = int(sys.stdin.readline())
    maxPow = [1 for i in xrange(1000005)]

    if n == 1:
        res = 0
    else:
        res = 1
        for p in primes:
            j = 2
            v = p*p
            while v <= n:
                res += 1
                v *= p

    print "Case #%d: %d" % (t+1, res)

