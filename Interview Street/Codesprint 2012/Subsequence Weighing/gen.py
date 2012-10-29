import sys
import random

T = 3
L = 100
MAXV = 100

print T
for i in xrange(T):
    print L
    a = [random.randint(1, MAXV) for i in xrange(L)]
    b = [random.randint(1, MAXV) for i in xrange(L)]
    print ' '.join(map(str, a))
    print ' '.join(map(str, b))
