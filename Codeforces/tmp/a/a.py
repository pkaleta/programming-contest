import sys

n = int(sys.stdin.readline())

d = [['.' for c in xrange(n)] for r in xrange(4)]

def opp(c):
    if c == 'a':
        return 'b'
    else:
        return 'a'

c = 'a'
for i in xrange(1, n, 2):
    d[0][i] = c
    d[0][i-1] = c
    c = opp(c)

c = 'a'
for i in xrange(2, n, 2):
    d[3][i] = c
    d[3][i-1] = c
    c = opp(c)

def nxt(c):
    if c == 'c':
        return 'd'
    elif c == 'd':
        return 'e'
    else:
        return 'c'

r = 1
c = 'c'
for i in xrange(1, n):
    d[r][i] = c
    d[r][i-1] = c
    if r == 1:
        r = 2
    else:
        r = 1
    c = nxt(c)

if n % 2 == 1:
    d[2][0] = d[3][0] = 'f'
    d[0][n-1] = d[1][n-1] = 'g'
else:
    d[2][0] = d[3][0] = 'f'
    d[2][n-1] = d[3][n-1] = 'g'

for line in d:
    print ''.join(line)
