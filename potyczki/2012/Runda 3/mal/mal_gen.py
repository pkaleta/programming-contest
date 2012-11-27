from random import randint

MAX_N = 5
MAX_SIZE = 10

n = randint(2, MAX_N)
print n

for i in xrange(n):
    x1 = randint(0, MAX_SIZE - 2)
    x2 = randint(x1 + 1, MAX_SIZE - 1)
    y1 = randint(0, MAX_SIZE - 2)
    y2 = randint(y1 + 1, MAX_SIZE - 1)
    print x1, y1, x2, y2
