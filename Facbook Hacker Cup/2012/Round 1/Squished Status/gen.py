import sys
import random

T = 20
MAX_M = 255
MAX_LEN = 30

print T
for i in xrange(T):
    m = random.randint(1, MAX_M)
    print m
    L = random.randint(1, MAX_LEN)
    t = []
    for j in xrange(L):
        t.append(str(random.randint(0, 9)))
    print ''.join(t)
