import sys
from itertools import permutations

T = int(sys.stdin.readline())

def brute(N):
    max_perm = []
    max_score = -1
    for perm in permutations(range(1, N + 1)):
        cur_score = score(perm)
        if cur_score > max_score:
            max_score = cur_score
            max_perm = perm
    return max_perm, max_score

def score(a):
    res = 0
    for i in xrange(1, N):
        res += a[i] * a[i - 1]
    return res

for t in xrange(T):
    N = int(sys.stdin.readline())
    a = [0 for i in xrange(N)]
    for i in xrange(N / 2):
        a[i] = 2 * i + 1
        a[N - i - 1] = 2 * (i + 1)
    if N % 2 == 1:
        a[N / 2] = N

    print score(a)
