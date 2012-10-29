import sys

T = int(sys.stdin.readline())
MOD = 1000000007

for t in xrange(T):
    n = int(sys.stdin.readline())
    city = []
    dist = map(int, sys.stdin.readline().split())
    pop = map(int, sys.stdin.readline().split())

    ret = 0

    for i in xrange(n):
        for j in xrange(i+1, n):
            ret += abs(dist[i] - dist[j]) * max(pop[i], pop[j])

    print ret % MOD
