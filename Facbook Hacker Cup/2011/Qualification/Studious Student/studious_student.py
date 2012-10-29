from copy import copy
import sys

def perms(a):
    if len(a) == 1:
        return [a]
    result = []
    for perm in perms(a[1:]):
        for i in xrange(len(perm) + 1):
            tmp = copy(perm)
            tmp.insert(i, a[0])
            result.append(tmp)
    return result

n = int(sys.stdin.readline())
for i in xrange(n):
    print sorted(map(''.join, perms(sys.stdin.readline().split()[1:])))[0]

