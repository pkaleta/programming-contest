import sys
import random

MAX_LEN = 1000
T = 100


print T

for t in xrange(T):
    n = random.randint(1, MAX_LEN)
    s = []
    for i in xrange(n):
        d = {1: 'a', 2: 'c', 3: 't', 4: 'g'}
        s.append(d[random.randint(1, 4)])

    print "".join(s)
