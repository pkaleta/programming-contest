import sys

b = [[0 for i in xrange(8)] for i in xrange(8)]

def foo(c):
    return (ord(c[0])-ord('a'), ord(c[1])-ord('0')-1)

rx, ry = foo(sys.stdin.readline()[:-1])
kx, ky = foo(sys.stdin.readline()[:-1])

for i in xrange(8):
    b[ry][i] = 1
    b[i][rx] = 1

b[ky][kx] = 1

def check(x, y):
    return x >= 0 and x <= 7 and y >= 0 and y <= 7

for dy in [-2, -1, 1, 2]:
    for dx in [-2, -1, 1, 2]:
        if abs(dy)+abs(dx) == 3:
            if check(rx+dx, ry+dy):
                b[ry+dy][rx+dx] = 1
            if check(kx+dx, ky+dy):
                b[ky+dy][kx+dx] = 1

res = 0
for i in xrange(8):
    for j in xrange(8):
        if b[i][j] == 0:
            res += 1

print res

