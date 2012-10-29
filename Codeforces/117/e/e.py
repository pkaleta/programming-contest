import sys
from collections import defaultdict
from copy import copy

n, L = map(int, sys.stdin.readline().split())
MOD = 1000000007

lengths = defaultdict(set)
dp = {}

sys.setrecursionlimit(1000000000)

for i in xrange(n):
    a, b = map(int, sys.stdin.readline().split())
    lengths[a].add((b, i))
    lengths[b].add((a, i))

def solve(prev_w, l, prev_t):
    state = (prev_w, l, prev_t)
    if state in dp:
        return dp[state]
    if l == 0:
        return 1
    if l < 0:
        return 0
    ret = 0
    if l == L:
        for length, widths in lengths.items():
            for (width, type) in widths:
                if type != prev_t:
                    ret += solve(width, l-length, type)
        dp[state] = ret % MOD
        return ret % MOD
    else:
        for (width, type) in lengths[prev_w]:
            if type != prev_t:
                ret += solve(width, l-prev_w, type)
        dp[state] = ret % MOD
        return ret % MOD

print solve(0, L, -1)
