import sys

T = int(sys.stdin.readline())

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    return a*b/gcd(a, b)

def updateLcm(old, n, res):
    new = old
    if old < lcm(old, n):
        new = lcm(old, n)
        res += 1

    return (res, new)


for t in xrange(T):
    n = int(sys.stdin.readline())
    isPrime = [True for i in xrange(1005)]
    isPrime[0] = isPrime[1] = False
    primes = []

    oldLcm = 1
    res = 1
    if (n > 1):
        for i in xrange(2, n+1):
            if isPrime[i]:
                primes.append(i)
                res, oldLcm = updateLcm(oldLcm, i, res)
                j = i*2
                while j <= n:
                    res, oldLcm = updateLcm(oldLcm, j, res)
                    isPrime[j] = False
                    j += i
    else:
        res = 0


    print "Case #%d: %d" % (t+1, res-len(primes))

