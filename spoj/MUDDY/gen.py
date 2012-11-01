import random

print 100
for t in xrange(100):
    r = random.randint(1, 100)
    c = random.randint(1, 100)
    print r, c
    for i in xrange(r):
        line = []
        for j in xrange(c):
            x = random.randint(1, 2)
            if x == 1:
                line.append('.')
            else:
                line.append('*')
        print "".join(line)
