import sys
from copy import copy

n = int(sys.stdin.readline())
for i in xrange(n):
    w = sys.stdin.readline().split()[1:]

    result = [w[0]]
    for i in xrange(1, len(w)):
        best = copy(result)
        best.insert(0, w[i]);
        for j in xrange(1, len(result) + 1):
            current = copy(result)
            current.insert(j, w[i])
            if ''.join(best) > ''.join(current):
                best = current
        result = best

    print ''.join(result)
