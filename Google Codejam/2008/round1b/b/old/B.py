import sys
from bisect import bisect_left

n = int(sys.stdin.readline())

primes = []
for line in open('10000.txt', 'r'):
    for x in line.split():
        primes.append(int(x))


for z in range(n):
    a, b, p = [int(x) for x in sys.stdin.readline().split()]
    h = {}
    for x in range(a, b+1):
        h[x] = x
    m = b+2
    pos = bisect_left(primes, p)
    for x in range(a, b+1):
        for y in range(x+1, b+1):
            i = pos
            while primes[i] <= x and primes[i] <= y:
                if x % primes[i] == 0 and y % primes[i] == 0:
                    m += 1
                    for k in range(a, b+1):
                        if (h[k] == h[x] or h[k] == h[y]) and k != x and k != y:
                            h[k] = m

                    h[x] = h[y] = m


                    break
                i += 1
    tmp = []
    result = 0
    for v in h.values():
        if not v in tmp:
            result += 1
        tmp.append(v)

    print "Case #%d: %d" %(z + 1, result)
