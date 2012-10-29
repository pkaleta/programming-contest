import sys
import random

a = []

print 100, 950, 3

for i in xrange(950):
    a.append(random.randint(1, 100))

print ' '.join(map(str, a))
