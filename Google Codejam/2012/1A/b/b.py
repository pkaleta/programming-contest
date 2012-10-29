import sys
from collections import defaultdict

T = int(sys.stdin.readline())

def solve(one_cost, two_cost):
    ret = 0
    stars = 0

    j = 0

    visited = defaultdict(int)
    while j < len(two_cost):
        if two_cost[j][0] <= stars:
            level = two_cost[j][1]
            stars += 2 - visited[level]
            visited[level] = 2
            j += 1
        else:
            ii = -1
            for i in xrange(len(one_cost)):
                level = one_cost[i][1]
                if one_cost[i][0] <= stars and not level in visited:
                    ii = i
                    break
            if ii == -1:
                return -1
            visited[level] = 1
            stars += 1
        ret += 1

    return ret


for t in xrange(T):
    N = int(sys.stdin.readline())
    one_cost = []
    two_cost = []
    costs = []

    for i in xrange(N):
        a, b = map(int, sys.stdin.readline().split())
        costs.append((b, a, i))

    costs = sorted(costs)

    one_cost = [(a, i) for b, a, i in costs][::-1]
    two_cost = [(b, i) for b, a, i in costs]

    ret = solve(one_cost, two_cost)

    if ret == -1:
        print "Case #%d: Too Bad" % (t + 1)
    else:
        print "Case #%d: %d" % (t + 1, ret)
